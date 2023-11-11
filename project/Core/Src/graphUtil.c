/**
 * @parent Core/Src
 * @file graphUtil.c
 * @author ayano
 * @date 11/6/23
 * @brief
*/
#include "graphUtil.h"


void coordScreen2Area(GraphArea area, Point screen_coord, Point *area_coord_out) {
    area_coord_out->is_screen_coord = false;
    if (!screen_coord.is_screen_coord) {
        area_coord_out->x = screen_coord.x;
        area_coord_out->y = screen_coord.y;
        return;
    }
    float y_ratio = area.height / SCREEN_H;
    float x_ratio = area.width / SCREEN_W;
    area_coord_out->x = screen_coord.x * x_ratio;
    area_coord_out->y = screen_coord.y * y_ratio;
}
void coordArea2Screen(GraphArea area, Point area_coord, Point *screen_coord_out) {
    screen_coord_out->is_screen_coord = true;
    if (area_coord.is_screen_coord) {
        screen_coord_out->x = area_coord.x;
        screen_coord_out->y = area_coord.y;
        return;
    }
    float y_ratio = area.height / SCREEN_H;
    float x_ratio = area.width / SCREEN_W;
    screen_coord_out->x = area_coord.x / x_ratio;
    screen_coord_out->y = area_coord.y / y_ratio;
}

void plotScatter(GraphArea area, Point area_coord) {
}
