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
    float y_ratio = (float)area.height / SCREEN_H;
    float x_ratio = (float)area.width / SCREEN_W;
    screen_coord_out->x = area_coord.x / x_ratio;
    screen_coord_out->y = area_coord.y / y_ratio;
}

void plotScatter(GraphArea area, Point area_coord) {
    if(!area_coord.is_screen_coord){
        Point pt;
        coordArea2Screen(area, area_coord, &pt);
        ST7735_DrawPixel(pt.x, pt.y, WHITE);
    }
    else{
        ST7735_DrawPixel(area_coord.x, area_coord.y, WHITE);
    }
}

int normalizeY(Coord val, Coord max_val, Coord min_val){
    double percent = (double)(val - min_val) / (max_val - min_val);
    return val * percent;
}

void plotData(DataArray* data, GraphArea area){
    smoothen(data, 1);
    for (int i = 0; i < data->data_pointer; ++i) {
        Point pt = {
            .x = i + area.graph_origin_pos.x,
            .y = normalizeY(data->data_smoothened[i], DATA_UPPER_LIMIT, DATA_LOWER_LIMIT) + area.graph_origin_pos.y,
            .is_screen_coord = true
        };
        plotScatter(area, pt);
    }
}

void makeGraphArea(GraphArea* area, Coord width, Coord height, Point upper_left, void *graph_origin_pos){
    area->width = width;
    area->height = height;
    area->upper_left = upper_left;
    if (graph_origin_pos == NULL) {
        area->graph_origin_pos.x = width / 2;
        area->graph_origin_pos.y = height / 2;
        area->graph_origin_pos.is_screen_coord = true;
    }
    else {
        area->graph_origin_pos = *(Point*)graph_origin_pos;
    }
}

