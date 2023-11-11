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


#endif//PROJECT_CONSTS_H
