#ifndef PROJECT_CALCULATE_SIDE_LENGTH_STRUCTURES_H_
#define PROJECT_CALCULATE_SIDE_LENGTH_STRUCTURES_H_

#define ERROR -1
#define SUCCESS 1
#define NUM_INPUT_VALUES 3

typedef struct triangle {
    float a;
    float b;
    float c;
} triangle;

typedef struct circle {
    float radius;
} circle;

typedef struct square {
    float side_length;
} square;

#endif  // PROJECT_CALCULATE_SIDE_LENGTH_STRUCTURES_H_
