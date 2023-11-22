/**
 * @parent Core/Inc
 * @file measurmentUtil.h
 * @author ayano
 * @date 11/14/23
 * @brief
*/

#ifndef PROJECT_DATAUTIL_H
#define PROJECT_DATAUTIL_H

#include "consts.h"
#include "mathUtils.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief the measured data
 * @param data data smoothened by running average
 * @param data_pointer index of the last added data, all data with index <= data_pointer are the latest
 * @param data_raw raw data collected from the sensor
 * @param filled whether this Array has been filled or not, this is used when calculating the running avg
 * @param max the max val of this dataset
 * @param min the min val of this dataset
 * @param peak_cnt if i-th index was marked true, this is a peak
 * @param valley_cnt if i-th index was marked true, this is a valley
 * @remark DO NOT CHANGE INDIVIDUAL ARRAY CAPACITY TO ANOTHER VALUE, CHANGE DATA_CAPACITY IN consts.h INSTEAD!
 */
typedef struct {
    Reading data_smoothened[DATA_CAPACITY];
    uint8_t data_pointer;
    Reading data_raw[DATA_CAPACITY];
    Boolean data_label[DATA_CAPACITY];
    Boolean filled;
    Reading max;
    Reading min;
    Boolean peak_mark[DATA_CAPACITY];
    Boolean valley_mark[DATA_CAPACITY];
} DataArray;

/**
 * @brief find the running avg based on the DataArray object and the count of element
 * @param avg_out DataArray object given to calculate
 * @param n the left and right interval length
 * @remark This will set the data at data_pointer to be the running avg of the raw data with interval n
 * @remark And this will smoothen the curve at the data_pointer position
 */
void getRunningAvg(DataArray *avg_out, uint8_t n, Boolean reiterate);

/**
 * @brief add a data point to the DataArray object
 * @param data data reading
 * @param avg_out DataArray object given to add
 */
void addData(Reading data, DataArray *avg_out);

/**
 * @brief smoothen the data with running avg
 * @param avg_out reference to data pending smoothen
 */
void smoothen(DataArray *avg_out, uint8_t smoothen);

/**
 * @brief update the data to find valley and peak
 * @param data_out pointer to data given and to be modified
 */
void updatePeakValley(DataArray *data_out);

/**
 * @brief get bpm from a measured data
 * @param data data given
 * @return bpm calculated from data given
 */
int getBPM(DataArray data);

void makeData(DataArray *data_out);

#endif//PROJECT_DATAUTIL_H
