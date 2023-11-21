/**
 * @parent Core/Src
 * @file measurmentUtil.c
 * @author ayano
 * @date 11/14/23
 * @brief
*/

#include "measurmentUtil.h"

void smoothen(DataArray* avg_out, uint8_t smoothen_iteration) {
    int end = avg_out->data_pointer;
    avg_out->data_pointer = 0;
    if (smoothen_iteration == 1){
        getRunningAvg(avg_out, RUNNING_AVG_INTERVAL, false);
    }
    for (int j = 0; j < smoothen_iteration; j++) {
        for (int i = 0; i <= end; ++i) {
            getRunningAvg(avg_out, RUNNING_AVG_INTERVAL, true);
        }
    }
}

void getRunningAvg(DataArray *avg_out, uint8_t n, Boolean reiterate){
        if (avg_out->data_pointer < n) n = avg_out->data_pointer;
        int begin = avg_out->data_pointer - n > 0 ? avg_out->data_pointer - n: 0;
        int end;
        if (avg_out->filled){
            if (avg_out->data_pointer + n > DATA_CAPACITY - 1){
                end = DATA_CAPACITY - 1;
            }
            else{
                end = avg_out->data_pointer + n;
            }
        }
        else{
            end = avg_out->data_pointer;
        }
        uint16_t sum = 0;
        for (int i = begin; i <= end; ++i) {
            if (!reiterate)
                sum += (i != avg_out->data_pointer) ? avg_out->data_raw[i] : 0;
            else
                sum += (i != avg_out->data_pointer) ? avg_out->data_smoothened[i] : 0;
        }
        // -1 for including end and another -1 for excluding the datapoint
        avg_out->data_smoothened[avg_out->data_pointer] = sum / (end - begin - 2);
}

void addData(Reading data, DataArray * avg_out){
    if(++avg_out->data_pointer == DATA_CAPACITY){
        avg_out->filled = 1;
        avg_out->data_pointer = 0;
    }
    avg_out->data_raw[avg_out->data_pointer] = data;
    getRunningAvg(avg_out, RUNNING_AVG_INTERVAL, false);
    smoothen(avg_out, 1);
    if(data > avg_out->max && within_inc(data, DATA_LOWER_LIMIT, DATA_UPPER_LIMIT)) avg_out->max = data;
    if(data < avg_out->min && within_inc(data, DATA_LOWER_LIMIT, DATA_UPPER_LIMIT)) avg_out->min = data;
}

void updatePeakValley(DataArray *data_out){
    memset(data_out->peak_mark, false, DATA_CAPACITY);
    memset(data_out->valley_mark, false, DATA_CAPACITY);
    uint8_t data_count = data_out->filled ? DATA_CAPACITY : data_out->data_pointer;
    uint16_t interval_len_ms = (data_count - 1) * SAMPLING_INTERVAL_MS;
    uint8_t peak_cnt = 0, valley_cnt = 0;
    smoothen(data_out, OPTIMAL_SMOOTHEN_ITERATION);
    int* diff_arr = malloc(data_count);
    diff_arr[data_count - 1] = 0;

    // get sgn of difference
    for (int i = 0; i < data_count - 1; i++){
        diff_arr[i] = sgn(data_out->data_smoothened[i] - data_out->data_smoothened[i + 1]);
    }

    // remove zero according to the neighboring node
    for (int i = 0; i < data_count - 1; ++i) {
        // because no diff data at data_count - 1
        if (i == data_count - 2)
            diff_arr[i] = sgn_remove_zero(diff_arr[i], diff_arr[i - 1]);
        else
            diff_arr[i] = sgn_remove_zero(diff_arr[i], diff_arr[i + 1]);
    }

    for (int i = 0; i < data_count - 1; ++i){
        // if it's 1 then -1, it's a turning pt
        int next = i == data_count - 2 ? -1 : 1;
        if (diff_arr[i] - diff_arr[i + next] == 2){
            peak_cnt++;
            data_out->peak_mark[i] = true;
        }
        else if(diff_arr[i + next] - diff_arr[i] == 2) {
            valley_cnt++;
            data_out->valley_mark[i] = true;
        }
    }
    free(diff_arr);
}

int getBPM(DataArray data){
    updatePeakValley(&data);
    uint8_t data_count = data.filled ? DATA_CAPACITY : data.data_pointer;
    uint16_t interval_len_ms = (data_count - 1) * SAMPLING_INTERVAL_MS;
    uint8_t peak = 0, valley = 0;
    for (int i = 0; i < data_count; ++i) {
        if (data.peak_mark[i]) peak++;
        else if (data.valley_mark[i]) valley++;
    }
    return (peak - 1) / s2m(ms2s(interval_len_ms));
}
