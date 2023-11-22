/**
 * @parent Core/Src
 * @file graphUtil.c
 * @author ayano
 * @date 11/6/23
 * @brief
*/
#include "graphUtil.h"


void coordScreen2Area(GraphArea area, Point screen_coord, Point *area_coord_out) {
    if (!screen_coord.is_screen_coord) {
        area_coord_out->x = screen_coord.x;
        area_coord_out->y = screen_coord.y;
        return;
    }
    area_coord_out->is_screen_coord = false;
    float y_ratio = area.height / SCREEN_H;
    float x_ratio = area.width / SCREEN_W;
    area_coord_out->x = screen_coord.x / x_ratio;
    area_coord_out->y = screen_coord.y / y_ratio;
}
void coordArea2Screen(GraphArea area, Point area_coord, Point *screen_coord_out) {
    if (area_coord.is_screen_coord) {
        screen_coord_out->x = area_coord.x;
        screen_coord_out->y = area_coord.y;
        return;
    }
    screen_coord_out->is_screen_coord = true;
    float y_ratio = (float) area_coord.y / (float) area.height;
    float x_ratio = (float) area_coord.x / (float) area.width;
    screen_coord_out->x = SCREEN_W * x_ratio;
    screen_coord_out->y = SCREEN_H * y_ratio;
}

void plotScatter(GraphArea area, Point area_coord) {
    if (!area_coord.is_screen_coord) {
        Point pt;
        coordArea2Screen(area, area_coord, &pt);
        ST7735_DrawPixel(pt.x, pt.y, WHITE);
    } else {
        ST7735_DrawPixel(area_coord.x, area_coord.y, WHITE);
    }
}

int normalizeY(Coord val, Coord max_val, Coord min_val) {
    double percent = (double) (val - min_val) / (max_val - min_val);
    Point t = {.x = 0, .y = 0, .is_screen_coord = true};
    GraphArea area = {
            .upper_left = {.x = 0, .y = 0, .is_screen_coord = true},
            .width = SCREEN_W,
            .height = SCREEN_H,
            .graph_origin_pos = {.x = 0, .y = SCREEN_H, .is_screen_coord = true}
    };
//    writeDouble(percent, t, area, WHITE, BLACK, MEDIUM_FONT);
    return area.height * percent;
}

void plotData(DataArray *data, GraphArea area) {
    smoothen(data, 1);
    for (int i = 0; i < data->data_pointer; ++i) {
        Point pt = {
                .x = i,
                .y = normalizeY(data->data_smoothened[i], DATA_UPPER_LIMIT,DATA_LOWER_LIMIT),
                .is_screen_coord = true};
        plotScatter(area, pt);
    }
}

void plotRawData(DataArray data, GraphArea area){
    for (int i = 0; i < data.data_pointer; ++i) {
        Point pt = {
                .x = i,
                .y = normalizeY(data.data_raw[i], DATA_UPPER_LIMIT,DATA_LOWER_LIMIT),
                .is_screen_coord = false};
        Point t = {.x = SCREEN_H / 2, .y = SCREEN_W / 2};
        writeInt(pt.y, t, area, WHITE, BLACK, MEDIUM_FONT);
        coordArea2Screen(area, pt, &pt);
        writeInt(pt.y, t, area, WHITE, BLACK, MEDIUM_FONT);
        plotScatter(area, pt);
    }

}

void writeString(char *buffer, Point coord, GraphArea area, Color color, Color bg_color, FontDef font) {
    if (!coord.is_screen_coord) {
        coordArea2Screen(area, coord, &coord);
    }
    ST7735_WriteString(coord.x, coord.y, buffer, font, color, bg_color);
}

void writeInt(int val, Point coord, GraphArea area, Color color, Color bg_color, FontDef font){
    char buffer[1024];
    memset(buffer, '\0', 1024);
    itoa(val, buffer, 10);
    writeString(buffer, coord, area, color, bg_color, font);
}

void writeDouble(double val, Point coord, GraphArea area, Color color, Color bg_color, FontDef font){
    char buffer[1024];
    memset(buffer, '\0', 1024);
    sprintf(buffer, "%g", val);
    writeString(buffer, coord, area, color, bg_color, font);
}

