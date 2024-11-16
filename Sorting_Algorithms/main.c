#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

void printArray(int array[], int size);

// BIG O notation

//
// O(n^2)
//

void bubbleSort(int array[], int size);
void insertionSort(int array[], int size);
void selectionSort(int array[], int size);

void mergeSort(int array[], int size);
void sortSubArray(int array[], int low, int high);
void merge(int array[], int left, int middle, int right);

int main()
{
    int nums[8] = {8,2,5,1,4,6,3,12};
    printArray(nums, 8);
    //bubbleSort(nums, 8);
    //insertionSort(nums, 8);
    //selectionSort(nums, 8);
    //mergeSort(nums, 8);
    //printArray(nums, 8);

    int minimums_pos = 0;

    for (int =0 ; i < 8; i++) {
        if (nums[i] < nums[minimums_pos]) {
            minimums_pos = i;
        }
    }

    minimum = nums[minimums_pos];

    return 0;
}

void printArray(int array[], int size) {
    // O(n)
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d", array[i]);
        if (i < size-1) {
            printf(",");
        }
    }
    printf(" ]\n");
}

void bubbleSort(int array[], int size) {
    // 2 4 8 26 82
    //       ^
    //     ^
    // O(n^2)
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void insertionSort(int array[], int size) {
    // 2 3 4 7 9
    //         ^    4
    // O(n^2)
    for (int i = 1; i < size; i++) {
        int j = i-1;
        int value = array[i];
        while (array[j] > value && j >= 0) {
            array[j+1] = array[j];  // Shift everything that is smaller to the right
            j--;
        }
        array[j+1] = value;
    }
}

void selectionSort(int array[], int size) {
    // O(n^2)
    // 2 3 4 6
    //
    int temp;
    for (int i = 0; i < size; i++) {
        int index_of_min = i;

        // Find smallest value in rest of array
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[index_of_min]) {
                index_of_min = j;
            }
        }

        temp = array[i];
        array[i] = array[index_of_min];
        array[index_of_min] = temp;
    }
}
// Merge sort is O(n*log(n))
// Split into two smaller arrays
// 2 4 7 3 0 9
// 2 4 7          |  3 0 9
// 2  |   4 7      |       3    |      0 9
// 2  |   4   | 7  |       3    |    0  |  9
// 2  |    4 7     |       3    |    0 9
//  2 4 7          |       0 3 9
//  0 2 3 4 7 9
// merge two sorted arrays
void mergeSort(int array[], int size) {
    sortSubArray(array, 0, size-1);
}

void sortSubArray(int array[], int low, int high) {
    // Post order
    // Base case: high - low = 0 so there is only one element which means it is sorted by default
    // Otherwise
    if (high - low >= 1) {
        int middle = (high + low) / 2;

        sortSubArray(array, low, middle); // bottom halfo
        sortSubArray(array, middle+1, high); // top half

        merge(array, low, middle, high);
    }
}

void merge(int array[], int left, int middle, int right) {
    int temp_array[50] = {0};
    int left_index = left;
    int right_index = middle+1;
    int temp_index = left;
    //merge two arrays until end of one is reached
    while (left_index <= middle && right_index <= right) {
        // place smaller of two elements in result and move on
        if (array[left_index] <= array[right_index]) {
            temp_array[temp_index++] = array[left_index++];
        }
        else {
            temp_array[temp_index++] = array[right_index++];
        }
    }

    if (left_index == middle+1) { // if at end of left array
        while (right_index <= right) { // copy in right subarray
            temp_array[temp_index++] = array[right_index++];
        }
    } // end if
    else { // if end of right array
        while (left_index <= middle) { // copy in left subarray
            temp_array[temp_index++] = array[left_index++];
        }
    }

    for (int i = left; i <= right; i++) { // copy back into original array
        array[i] = temp_array[i];
    }
}
