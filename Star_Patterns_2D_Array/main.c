#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20
void draw_cross_to_grid(int size);
void draw_circle_to_grid(int size, int radius);
int main()
{
    printf("Hello world!\n");

    // Initialise 2D array of chars
    char pattern[GRID_SIZE][GRID_SIZE];
    char * pattern2 = malloc(sizeof(char) * GRID_SIZE*GRID_SIZE);

    // Fill array with some characters
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            pattern[row][col] = '.';
            *(pattern2 + row*GRID_SIZE + col) = '.';
        }
    }

    // Access random characters
    pattern[1][1] = 'f';
    *(pattern2 + 2*GRID_SIZE + 0)  = 'g'; //pattern[2][0]



    // Use star patterns from yesterday to write into 2D array
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (row == col || row == -col + GRID_SIZE) {
                pattern[row][col] = '*';
                *(pattern2 + row*GRID_SIZE + col) = '*';
            }
        }
    }


    int radius = 4;
    for (int row = GRID_SIZE; row >= 0; row--) {
        for (int col = 0; col < GRID_SIZE; col++) {
            int center_x = row - GRID_SIZE/2;
            int center_y = col - GRID_SIZE/2;
            if (center_x*center_x + center_y*center_y <= radius*radius) {
               pattern[row][col] = '*';
               *(pattern2 + row*GRID_SIZE + col) = '*';
            }

        }
    }

 // Print 2D array of chars
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%c ", pattern[row][col]);
        }
        printf("\n");
    }
    printf("\n");printf("\n");

    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%c ", *(pattern2 + row*GRID_SIZE + col));
        }
        printf("\n");
    }
    // Use pointer notation to do the above

    free(pattern2);
    return 0;
}

void draw_cross_to_grid(int size) {
    for (int y = size; y >= 0; y--) {
        for (int x = 0; x < size; x++) {
            if (y == x || y == -x + size) {
                printf("* ");
            } else {
                printf("  ");
            }

        }
        printf("\n");
    }
}

void draw_circle_to_grid(int size, int radius, char * grid) {
    for (int row = GRID_SIZE; row >= 0; row--) {
        for (int col = 0; col < GRID_SIZE; col++) {
            int center_x = row - GRID_SIZE/2;
            int center_y = col - GRID_SIZE/2;
            if (center_x*center_x + center_y*center_y <= radius*radius) {
               *(grid + row*GRID_SIZE + col) = '*';
            }

        }
    }
}



void f(int x) {
    int z = x * x;
    x = 6;
}
