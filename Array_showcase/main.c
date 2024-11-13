#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[20];
    int * digits = malloc(20 * sizeof(int));

    printf("nums: %d\n", nums);


    for (int i = 0; i < 20; i++) {
        nums[i] = i;        //Subscript notation
        *(digits + i) = i;  //Pointer notation
    }

    nums[0] = 6;
    nums[3] = 47;

    *(digits + 0) = 6;
    *(digits + 3) = 47;

    for (int i = 0; i < 20; i++) {
        printf("%10s[%2d]: %2d\n", "nums", i, nums[i]);
        printf("%10s[%2d]: %2d\n", "digits", i, digits[i]);
    }

    free(digits);
    return 0;
}
