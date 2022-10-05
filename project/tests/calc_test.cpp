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
    free(tst_triangle);
}

TEST(Existance, negative_length) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -100;
    tst_triangle->b = 1;
    tst_triangle->c = -100;
    EXPECT_FALSE(check_if_triangle_exists(*tst_triangle));
    free(tst_triangle);
}

TEST(Existance, too_long_sides) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 100;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_FALSE(check_if_triangle_exists(*tst_triangle));
    free(tst_triangle);
}

TEST(Calculation, semi_perimeter_bad_triangle){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(ERROR, calc_semiperimeter(*tst_triangle));
    free(tst_triangle);
}

TEST(Calculation, semi_perimeter_fine_scenario){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(1.5, calc_semiperimeter(*tst_triangle));
    free(tst_triangle);
}

TEST(Calculation, sq_bad_triangle){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(ERROR, calc_sq(*tst_triangle));
    free(tst_triangle);
}

TEST(Calculation, sq_fine_scenario){
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;
    EXPECT_EQ(6, calc_sq(*tst_triangle));
    free(tst_triangle);
}

TEST(Calculation, radius_calc_bad_triangle) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = -1;
    tst_triangle->b = 1;
    tst_triangle->c = 1;
    EXPECT_EQ(ERROR, calc_radius(*tst_triangle));
    free(tst_triangle);
}

TEST(Calculation, radius_calc_fine_scenario) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;
    EXPECT_EQ(2.5, calc_radius(*tst_triangle));
    free(tst_triangle);
}

TEST(Calculation, square_side_length_fine_scenario) {
    circle * tst_circle = (circle*)malloc(1 * sizeof(circle));
    tst_circle->radius = 1;
    EXPECT_EQ(2, calc_square_side_length(*tst_circle));
    free(tst_circle);
}

TEST(Creation, create_triangle_fine_scenario) {
    char input[] = "3 4 5";
    FILE * fp;
    fp = fmemopen(input, strlen(input), "r");
    //fprintf(fp, input);
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;

    triangle * tested_triangle;
    create_triangle(fp, &tested_triangle);
    EXPECT_EQ(tst_triangle->a, tested_triangle->a);
    EXPECT_EQ(tst_triangle->b, tested_triangle->b);
    EXPECT_EQ(tst_triangle->c, tested_triangle->c);
    free(tst_triangle);
    free(tested_triangle);
    fclose(fp);
}

TEST(Creation, create_circle_fine_scenario) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;

    circle * users_circle;
    EXPECT_EQ(SUCCESS, create_circle(*tst_triangle, &users_circle));
    free(tst_triangle);
    free(users_circle);
}

TEST(Creation, create_triangle_bad_triangle) {
   char input[] = "-3 -4 -5";
    FILE * fp;
    fp = fmemopen(input, strlen(input), "r");
    //fprintf(fp, input);
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;

    triangle * tested_triangle;
    
    EXPECT_EQ(ERROR, create_triangle(fp, &tested_triangle));
    free(tst_triangle);
    fclose(fp);
}

TEST(Creation, create_square_fine_scenario) {
    circle * tst_circle = (circle*)malloc(1 * sizeof(circle));
    tst_circle->radius = 2.5;

    square * users_square;
    EXPECT_EQ(SUCCESS, create_square(*tst_circle, &users_square));
    free(tst_circle);
    free(users_square);
}

TEST(Creation, fscanf_failure) {
    char input[] = "3 4";
    FILE * fp;
    fp = fmemopen(input, strlen(input), "r");
    //fprintf(fp, input);
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    tst_triangle->a = 3;
    tst_triangle->b = 4;
    tst_triangle->c = 5;

    triangle * tested_triangle;
    
    EXPECT_EQ(-1, create_triangle(fp, &tested_triangle));
    free(tst_triangle);
    free(tested_triangle);
    fclose(fp);
}

TEST(Memory, memory_bad_alloc) {
    EXPECT_EQ(NULL, safe_malloc(0));
}

TEST(Memory, memory_freeing_fine_scenario) {
    triangle * tst_triangle = (triangle*)malloc(1 * sizeof(triangle));
    circle * tst_circle = (circle*)malloc(1 * sizeof(circle));
    square * tst_square = (square*)malloc(1 * sizeof(square));

    EXPECT_EQ(NULL, free_memory(tst_triangle, tst_circle, tst_square));
}
