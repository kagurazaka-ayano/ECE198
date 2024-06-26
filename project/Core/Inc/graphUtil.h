/**
 * @parent Core/Inc
 * @file graphUtil.h
 * @author ayano
 * @date 11/6/23
 * @brief utils used in producing a graph
*/

#pragma once

#ifndef PROJECT_GRAPHUTIL_H
#define PROJECT_GRAPHUTIL_H

#include "ST7735.h"
#include "consts.h"
#include "dataUtil.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief a Point class
 */
typedef struct {
    // x coord
    Coord x;
    // y coord
    Coord y;
    // whether this Point is a screen coord(only for quality of life purpose)
    Boolean is_screen_coord;
} Point;


/**
 * @brief area for a graph to be plotted
 */
typedef struct {
    // upper left coord of area
    Point upper_left;
    // area width
    Coord width;
    // area height
    Coord height;
    // origin pos of area, this is only used for plotting functions
    Point graph_origin_pos;
} GraphArea;


/**
 * @brief translate the screen coord to area coord
 * @param area graphing area given
 * @param screen_coord coordinate on the screed
 * @param x_out translated x area coord pointer
 * @param y_out translated y area coord pointer
 */
void coordScreen2Area(GraphArea area, Point screen_coord, Point *area_coord_out);

/**
 * @brief translate the area coord to screen coord
 * @param area graphing area given
 * @param x area x coord
 * @param y area y coord
 * @param x_out translated x coord pointer
 * @param y_out translated y coord pointer
 */
void coordArea2Screen(GraphArea area, Point area_coord, Point *screen_coord_out);

/**
 * @brief plot one point in the given area
 * @param area graphing area
 * @param area_coord point to plot in screen coord
 */
void plotScatter(GraphArea area, Point area_coord);

void plotData(DataArray *data, GraphArea area);

void writeString(char *buffer, Point coord, GraphArea area, Color color, Color bg_color, FontDef font);

void writeInt(int val, Point coord, GraphArea area, Color color, Color bg_color, FontDef font);

void writeDouble(double val, Point coord, GraphArea area, Color color, Color bg_color, FontDef font);

void plotRawData(DataArray data, GraphArea area);

int normalizeY(Coord val, Coord max_val, Coord min_val);

#endif//PROJECT_GRAPHUTIL_H
