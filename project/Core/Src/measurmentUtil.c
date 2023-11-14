/**
 * @parent Core/Src
 * @file measurmentUtil.c
 * @author ayano
 * @date 11/14/23
 * @brief
*/

#include "measurmentUtil.h"

void smoothen(DataArray* avg_out) {
    int end = avg_out->data_pointer;
    avg_out->data_pointer = 0;
    for (int i = 0; i <= end; ++i) {
        getRunningAvg(avg_out, RUNNING_AVG_INTERVAL);
    }
}

void getRunningAvg(DataArray *avg_out, uint8_t n){
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
            sum += (i != avg_out->data_pointer) ? avg_out->data_raw[i] : 0;
        }
        // -1 for including end and another -1 for excluding the datapoint
        avg_out->data[avg_out->data_pointer] = sum / (end - begin - 2);
}

void addData(Reading data, DataArray * avg_out){
    if(++avg_out->data_pointer == DATA_CAPACITY){
        avg_out->filled = 1;
        avg_out->data_pointer = 0;
    }
    avg_out->data_raw[avg_out->data_pointer] = data;
    getRunningAvg(avg_out, RUNNING_AVG_INTERVAL);
}
