#include <stdio.h>
#include <malloc.h>
#include "structures.h"
#include "methods.h"

int main() {
    printf("Input lengths of triangle needed (a, b, c)...\n");
    FILE *fp;
    fopen_s(&fp, "C:\\Users\\user\\Desktop\\Lernung\\untitled\\ABC.txt", "r");


    if(!fp) {
        printf("Can not open file...\n");
        return 0;
    }

    triangle *users_triangle = (triangle*)malloc(1 * sizeof(triangle));
    circle *users_circle = (circle *) malloc(1 * sizeof(circle));
    square *users_square = (square *) malloc(1 * sizeof(square));

    fscanf_s(fp, "%f%f%f", &users_triangle->a, &users_triangle->b, &users_triangle->c);

    printf("Triangle inputted: a = %f, b = %f, c = %f\n\n", users_triangle->a, users_triangle->b, users_triangle->c);
    if(!check_if_triangle_exists(*users_triangle)) {
        printf("Triangle does not exist...\n");
        return 0;
    }

    users_circle->radius = calc_radius(*users_triangle);
    printf("Radius of circle circumscribed about a triangle: r = %f\n\n", users_circle->radius);

    users_square->side_length = calc_square_side_length(*users_triangle);
    printf("Length of square`s side: l = %f\n\n", users_square->side_length);

    free(users_triangle);
    free(users_square);
    free(users_circle);
    fclose(fp);
    return 0;
}
