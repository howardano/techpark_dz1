#include "methods.h"
#include <math.h>
#include <stdbool.h>

float calc_semiperimeter(triangle trngle) {
    return (trngle.a + trngle.b + trngle.c) / 2;
}

float calc_sq(triangle trngle) {
    float semi_perimeter = calc_semiperimeter(trngle);
    return sqrtf((float) (semi_perimeter * (semi_perimeter - trngle.a) * (semi_perimeter - trngle.b) * (semi_perimeter - trngle.c)));
}

float calc_radius(triangle trngle) {
    return trngle.a * trngle.b * trngle.c / (4 * calc_sq(trngle));
}

float calc_square_side_length(triangle trngle) {
    return 2* calc_radius(trngle);
}

bool check_if_triangle_exists(triangle trngle) {
    if(trngle.a < 0 || trngle.b < 0 || trngle.c < 0)
        return false;
    return ((trngle.a < trngle.b + trngle.c) && (trngle.b < trngle.a + trngle.c) && (trngle.c < trngle.a + trngle.b)) ? true : false;
}