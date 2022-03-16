#ifndef PROJECT_CALCULATE_SIDE_LENGTH_METHODS_H_
#define PROJECT_CALCULATE_SIDE_LENGTH_METHODS_H_

#include <stdbool.h>
#include "structures.h"

float calc_semiperimeter(triangle trngle);
float calc_sq(triangle trngle);
float calc_radius(triangle trngle);
float calc_square_side_length(triangle trngle);
bool check_if_triangle_exists(triangle trngle);

#endif   // PROJECT_CALCULATE_SIDE_LENGTH_METHODS_H_
