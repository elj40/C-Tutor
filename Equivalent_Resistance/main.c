#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPECTED_RESISTORS 100

int main()
{
    int resistors_count;
    float resistor_values[MAX_EXPECTED_RESISTORS];

    printf("How many resistors do you have?\n");
    scanf("%d", &resistors_count);

    printf("Please enter your resistor values (Ohm):\n");
    for (int i = 0; i < resistors_count; i++) {
        scanf("%f", (resistor_values + i));
    }

    // In series
    float series_eq = 0;
    for (int i = 0; i < resistors_count; i++) {
        series_eq += *(resistor_values +i);
    }


    // Format so it looks nicer?
    printf("Series equivalent: %f\n", series_eq);

    // In parallel
    float parallel_eq;
    for (int i = 0; i < resistors_count; i++) {
        parallel_eq += 1/ *(resistor_values + i);

    }

    parallel_eq = 1/parallel_eq;

    //Format this too?
    printf("Parallel equivalent: %f\n", parallel_eq);
    return 0;
}
