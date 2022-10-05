#ifndef PROJECT_CALCULATE_SIDE_LENGTH_METHODS_H_
#define PROJECT_CALCULATE_SIDE_LENGTH_METHODS_H_



#include <stdbool.h>
#include "structures.h"
#include <stddef.h>
#include <stdio.h>

float calc_semiperimeter(triangle trngle);
float calc_sq(triangle trngle);
float calc_radius(triangle trngle);
float calc_square_side_length(circle crcl);
bool check_if_triangle_exists(triangle trngle);
int create_triangle(FILE * fp, triangle **users_triangle);
int create_circle(triangle trngle, circle **users_circle);
int create_square(circle crcl, square **users_square);
void *safe_malloc(size_t size);
void *free_memory(triangle *trngle, circle *crcl, square *sqre);
#endif   // PROJECT_CALCULATE_SIDE_LENGTH_METHODS_H_
