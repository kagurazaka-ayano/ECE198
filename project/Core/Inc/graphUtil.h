/**
 * @parent Core/Inc
 * @file graphUtil.h
 * @author ayano
 * @date 11/6/23
 * @brief utils used in producing a graph
*/

#ifndef PROJECT_GRAPHUTIL_H
#define PROJECT_GRAPHUTIL_H

#include "ST7735.h"
#include "consts.h"

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
    Coord upper_left;
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
 * @brief plot a scatter plot in given graphing area
 * @param area graphing area
 * @param area_coord point to plot in screen coord
 */
void plotScatter(GraphArea area, Point area_coord);


#endif//PROJECT_GRAPHUTIL_H
