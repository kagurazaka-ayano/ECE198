/**
 * @parent Core/Src
 * @file mathUtils.h
 * @author ayano
 * @date 11/11/23
 * @brief
*/

#ifndef PROJECT_MATHUTILS_H
#define PROJECT_MATHUTILS_H

#include <math.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define sgn(x) (((x) > 0) ? ((x) == 0 ? 0 : 1) : -1)
#define sgn_remove_zero(x, prev) (((x) == 0) ? ((prev) > 0) ? (1) : (-1) : 1)
#define within_inc(val, x, y) (((max((x), (y))) >= (val) && (val) >= (min((x), (y)))))
#define within_ex_left(val, x, y) ((max((x), (y))) > (val) && (val) >= (min((x), (y))))
#define within_ex_right(val, x, y) ((max((x), (y))) >= (val) && (val) > (min((x), (y))))
#define within_ex_both(val, x, y) ((max((x), (y))) > (val) && (val) > (min((x), (y))))
#define ms2s(time) ((double)(time) * 1e-3)
#define s2ms(time) ((double)(time) * 1e3)
#define s2m(time) ((double)(time) / 60.0)
#define m22(time) ((double)(time) * 60.0)

#endif//PROJECT_MATHUTILS_H
