#include <stdio.h>

int main() {
    // Declare simple variables
    // Declare pointers for the variables
    int x = 7;
    int * x_ptr = &x;
    int * x_ptr_ptr = &x_ptr;

    printf("x:            %d\n", x);
    printf("x address:    %d\n", &x);
    printf("x_ptr:        %d\n", x_ptr);
    printf("x_ptr adress: %d\n", &x_ptr);
    printf("x_ptr_ptr: %d\n", x_ptr_ptr);

    printf("x:            %d\n", x);
    printf("*x_ptr:       %d\n", *x_ptr);
    printf("*x_ptr_ptr:   %d\n", *x_ptr_ptr);
    printf("**x_ptr_ptr:  %d\n", *(int *)(*x_ptr_ptr));

    return 0;
}
