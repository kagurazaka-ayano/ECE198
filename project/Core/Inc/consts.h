/**
 * @parent Core/Inc
 * @file consts.h
 * @author ayano
 * @date 11/6/23
 * @brief constants that will be used
*/

#ifndef PROJECT_CONSTS_H
#define PROJECT_CONSTS_H

#include "ST7735.h"
#include "fonts.h"

extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;

/***** type define start *****/

typedef uint8_t Coord;
typedef unsigned int Color;
typedef uint8_t Boolean;
typedef uint32_t Reading;

/***** type define end *****/

/***** screen consts start *****/
#define SCREEN_W ST7735_WIDTH
#define SCREEN_H ST7735_HEIGHT
#define SMALL_FONT Font_7x10
#define MEDIUM_FONT Font_11x18
#define LARGE_FONT Font_16x26
#define SMALL_FONT_W 7
#define SMALL_FONT_H 10
#define MEDIUM_FONT_W 11
#define MEDIUM_FONT_H 18
#define LARGE_FONT_W 16
#define LARGE_FONT_H 26
/***** screen consts end *****/

/***** part consts start *****/

#define PORT_LED_OUT GPIOC
#define PIN_LED_OUT GPIO_PIN_0

/***** part consts end *****/

/***** measurement consts start *****/

#define SAMPLING_INTERVAL_MS 500
#define SAMPLING_RATE (1e3 / SAMPLING_INTERVAL_MS)
// this should be power of 2
#define DATA_CAPACITY 128
// tbd based on sensor data
#define HYSTERESIS_INIT_UPPER_THRESHOLD 400
#define HYSTERESIS_INIT_LOWER_THRESHOLD 300
// - 1 because we exclude the data at the data_pointer
#define RUNNING_AVG_INTERVAL ((DATA_CAPACITY >> 5) - 1)

/***** measurement consts end *****/

#endif//PROJECT_CONSTS_H
