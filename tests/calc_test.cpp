#include <gtest/gtest.h>
#include <math.h>

extern "C" {
    #include "structures.h"
    #include "methods.h"
}

TEST(Existance, fine_scenario) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_TRUE(check_if_triangle_exists(*tst_triangle));
}

TEST(Existance, negative_length) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -100;
    tst_triangle->b = 1;
    tst_triangle->c = -100;
    EXPECT_FALSE(check_if_triangle_exists(*tst_triangle));
}

TEST(Existance, too_long_sides) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 100;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_FALSE(check_if_triangle_exists(*tst_triangle));
}

TEST(Calculation, semi_perimeter_bad_triangle){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(-1, calc_semiperimeter(*tst_triangle));
}

TEST(Calculation, semi_perimeter_fine_scenario){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(1.5, calc_semiperimeter(*tst_triangle));
}

TEST(Calculation, sq_bad_triangle){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(-1, calc_sq(*tst_triangle));
}

TEST(Calculation, sq_fine_scenario){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;
    EXPECT_EQ(6, calc_sq(*tst_triangle));
}

TEST(Calculation, radius_calc_bad_triangle) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(-1, calc_radius(*tst_triangle));
}

TEST(Calculation, radius_calc_fine_scenario) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;
    EXPECT_EQ(2.5, calc_radius(*tst_triangle));
}

TEST(Calculation, square_side_length_bad_triangle) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(-1, calc_square_side_length(*tst_triangle));
}

TEST(Calculation, square_side_length_fine_scenario) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;
    EXPECT_EQ(5, calc_square_side_length(*tst_triangle));
}
