#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 0 and RAND_MAX
    int random_number = rand();
    printf("RAND_MAX: %d\n", RAND_MAX);
    printf("Random number between 0 and RAND_MAX: %d\n", random_number);

    // Generate a random number between 0 and 5 (exclusive)
    // Exclusive range = max - min + min
    int rand_num = rand() % 5;
    printf("Random number between 0 and 5: %d\n", rand_num);

    // Generate a random number between 6 and 9 (inclusive)
    // Inclusive range = (max - min + 1) + min
    rand_num = rand() % (4) + 6;
    printf("Random number between 6 and 9: %d\n", rand_num);

    // Generate a random number between -10 and 5 (inclusive)
    rand_num = rand() % (5 - -10 + 1)  -10;
    printf("Random number between -10 and 5: %d\n", rand_num);

    // Generate a random float between 0 and 1
    // Convert value/max = float from 0 to 1
    // value is rand()
    // max is RAND_MAX
    float rand_float = (float) rand() / RAND_MAX;
    printf("Random float between 0 and 1: %f\n", rand_float);

    // Generate a random float between 0 and 50
    // % to mark
    // 60% for a paper out of 50
    // 0..1 * 33 = 0
    rand_float = (float) rand() / RAND_MAX * 50;
    printf("Random float between 0 and 50: %f\n", rand_float);

    // Generate a random float between 12 and 18
    rand_float = (float) rand() / RAND_MAX * (18 -12) + 12;
    printf("Random float between 12 and 18: %f\n", rand_float);

    // Simulate a coin flip (0 or 1)
    int coin_value = rand() % 2;

    if (coin_value == 0) {
        printf("Tails\n");
    } else {
        printf("Heads\n");
    }


    // Simulate rolling a 6-sided die (1 to 6)
    // print value of a random dice roll
    rand_num = rand() % (5 + 1) + 1;

    printf("The dice rolled: %d\n", rand_num);

    return 0;
}
