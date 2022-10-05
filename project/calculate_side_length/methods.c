#include "methods.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <stddef.h>
#include <stdlib.h>

float calc_semiperimeter(triangle trngle) {
    if (!check_if_triangle_exists(trngle)) {
        return ERROR;
    }
    return (trngle.a + trngle.b + trngle.c) / 2;
}

float calc_sq(triangle trngle) {
    if (!check_if_triangle_exists(trngle)) {
        return ERROR;
    }
    float semi_perimeter = calc_semiperimeter(trngle);
    return sqrt((
    semi_perimeter *
    (semi_perimeter - trngle.a) *
    (semi_perimeter - trngle.b) *
    (semi_perimeter - trngle.c)));
}

float calc_radius(triangle trngle) {
    if (!check_if_triangle_exists(trngle)) {
        return ERROR;
    }
    return trngle.a * trngle.b * trngle.c / (4 * calc_sq(trngle));
}

float calc_square_side_length(circle crcl) {
    return 2 * crcl.radius;
}

bool check_if_triangle_exists(triangle trngle) {
    if (trngle.a < 0 || trngle.b < 0 || trngle.c < 0)
        return false;
    return ((trngle.a < trngle.b + trngle.c) &&
    (trngle.b < trngle.a + trngle.c) &&
    (trngle.c < trngle.a + trngle.b));
}

int create_triangle(FILE * fp, triangle **users_triangle) {
    *users_triangle = (triangle*) safe_malloc(1 * sizeof(triangle));

    int check = fscanf(fp, "%f%f%f", &(*users_triangle)->a, &(*users_triangle)->b, &(*users_triangle)->c);
    if (check != NUM_INPUT_VALUES) {
        return ERROR;
    }
    if (!check_if_triangle_exists(**users_triangle)) {
        free(*users_triangle);
        return ERROR;
    }
    return SUCCESS;
}

int create_circle(triangle trngle, circle **users_circle) {
    *users_circle = (circle*) safe_malloc(1 * sizeof(circle));
    (*users_circle)->radius = calc_radius(trngle);
    return SUCCESS;
}

int create_square(circle crcl, square **users_square) {
    *users_square = (square*) safe_malloc(1 * sizeof(square));
    (*users_square)->side_length = calc_square_side_length(crcl);
    return SUCCESS;
}

void *safe_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    void *ptr = malloc(size);
    return ptr;
}

void *free_memory(triangle * trngle, circle * crcl, square * sqre) {
    free(trngle);
    free(crcl);
    free(sqre);
    return NULL;
}

