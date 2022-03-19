#include <stdio.h>
#include "structures.h"
#include "methods.h"
#include <malloc.h>

int main() {
    printf("Input lengths of triangle needed (a, b, c)...\n");

    triangle * users_triangle;
    if (create_triangle(stdin, &users_triangle) == ERROR) {
        return 0;
    }

    printf("Triangle inputted: a = %f, b = %f, c = %f\n\n",
    users_triangle->a, users_triangle->b, users_triangle->c);

    circle * users_circle;
    create_circle(*users_triangle, &users_circle);
    printf("Radius of circle circumscribed about a triangle: r = %f\n\n", users_circle->radius);

    square * users_square;
    create_square(*users_circle, &users_square);
    printf("Length of square`s side: l = %f\n\n", users_square->side_length);

    free_memory(users_triangle, users_circle, users_square);
    return 0;
}
