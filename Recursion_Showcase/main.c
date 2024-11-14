#include <stdio.h>
#include <stdlib.h>

void my_first_recursion() {
    printf("Hello\n");
    my_first_recursion();
}

void print_list_with_recursion(int list[], int pos, int end) {
    printf("In this function, pos is %d\n", pos);
    if (pos == end) {
        return;
    } else {
        printf("list[%d] = %d\n", pos, list[pos]);
        print_list_with_recursion(list, pos+1, end);
    }
    printf("In this function, pos was %d\n", pos);
}

int fibonacci(int pos) {
    if (pos == 0) {
            return 0;
    }
    if (pos == 1) {
            return 1;
    }
    return fibonacci(pos-1) + fibonacci(pos-2);
}

int binary_search(int list[], int target, int low, int high) {
    int middle = (low + high) / 2;
    printf("Middle: %d\n", middle);
    if (list[middle] == target) return middle;
    else {
        if (list[middle] < target) {
            return binary_search(list, target, middle, high);
        } else {
            return binary_search(list, target, low, middle);
        }
    }
}

// factorial(4) = 4*3*2*1
// factorial(3) = 3*2*1
// factorial(n) = 4*factorial(n-1)
// factorial(1) = 1
int factorial(int n) {
    if (n == 0) return 1;
    return n*factorial(n-1);
}


int main()
{
    printf("Hello world!\n");

    // Print list with recursion
    int nums[10] = {2,4,6,8,10,12,13,16,17,18};

    //print_list_with_recursion(nums, 0, 10);
    // Fibonacci with recursion
    // 0,1,1,2,3,5,8,11,19...
    printf("Fibonacci 0: %d\n", fibonacci(0));
    printf("Fibonacci 1: %d\n", fibonacci(1));
    printf("Fibonacci 2: %d\n", fibonacci(2));
    printf("Fibonacci 3: %d\n", fibonacci(3));
    printf("Fibonacci 100: %d\n", fibonacci(20));


    // Binary search with recursion
    // Find position of some element
    // {2,4,6,8,10,12,13,16,17,18}
    //  12,13,16,17,18
    //      ^
    // 16,17,18
    //     ^

    int long_array[1000];
    for (int i = 0; i<1000; i++) {

        long_array[i] = i;
    }
    printf("Position of number 2: %d\n", binary_search(long_array, 51, 0, 1000));
    //printf("Position of number 18: %d\n", binary_search(nums, 18, 0, 10));



    // Factorial with recursion
    // 1, 2, 6, 24
    printf("factorial(1) = %d\n", factorial(1));
    printf("factorial(2) = %d\n", factorial(2));
    printf("factorial(3) = %d\n", factorial(3));
    printf("factorial(8) = %d\n", factorial(8));

    return 0;
}


