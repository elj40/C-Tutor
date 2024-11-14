#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var = 3;
    int * var_ptr = &var;
    printf("Var: %d\n", var);
    f(var);
    printf("Var after: %d\n", var);
    printf("\n");
    printf("Var: %d\n", var);
    f_reference(var_ptr);
    printf("Var after: %d\n", var);
    return 0;
}

void f(int x) { // Pass by value
    x = 10;
}

void f_reference(int * x) { // Pass by reference
    *x = 10;
}
