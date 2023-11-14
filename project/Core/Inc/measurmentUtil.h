/**
 * @parent Core/Inc
 * @file measurmentUtil.h
 * @author ayano
 * @date 11/14/23
 * @brief
*/

#ifndef PROJECT_MEASURMENTUTIL_H
#define PROJECT_MEASURMENTUTIL_H

#include "consts.h"


/**
 * @brief the measured data
 * @param data data smoothened by running average
 * @param data_pointer index of the last added data, all data with index <= data_pointer are the latest
 * @param data_raw raw data collected from the sensor
 * @param filled whether this Array has been filled or not, this is used when calculating the running avg
 */
typedef struct {
    Reading data[DATA_CAPACITY];
    uint8_t data_pointer;
    Reading data_raw[DATA_CAPACITY];
    Boolean filled;
} DataArray;

/**
 * @brief find the running avg based on the DataArray object and the count of element
 * @param avg_out DataArray object given to calculate
 * @param n the left and right interval length
 * @remark This will set the data at data_pointer to be the running avg of the raw data with interval n
 * @remark And this will smoothen the curve at the data_pointer position
 */
void getRunningAvg(DataArray* avg_out, uint8_t n);

/**
 * @brief add a data point to the DataArray object
 * @param data data reading
 * @param avg_out DataArray object given to add
 */
void addData(Reading data, DataArray* avg_out);

/**
 * @brief smoothen the data with running avg
 * @param avg_out data pending smoothen
 */
void smoothen(DataArray* avg_out);



#endif//PROJECT_MEASURMENTUTIL_H
