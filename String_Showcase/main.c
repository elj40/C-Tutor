#include <stdio.h>
#include <stdlib.h>

// We can make life a little easier with string.h
#include <string.h>

void print_capitalise_string(char * string); //TODO: write this function
int count_ls_in_string(char * string);

int main()
{
    // So far we havee mainly used strings just to print stuff out
    printf("Hello world!\n");
    // Strings are just an array of characters

    // Two ways to define a string
    char * pointer_string = "I am a string initialised as a pointer";
    char array_string[] = "i am a string initialised as an array";

    printf("Pointer string: %s\n", pointer_string);
    printf("Array string:   %s\n", array_string);

    // Strings are one character longer than we think, why?
    char string_1_to_9[] = "123456789";
    printf("Length of string_1_to_9: %d\n", sizeof(string_1_to_9));
    printf("Length of string_1_to_9 from string.h: %d\n", strlen(string_1_to_9));


    // How can we print a string all caps without knowing length of string?
    print_capitalise_string(array_string);
    // How can we count the number of l's in a string without knowing its length?
    int l_count = count_ls_in_string("lewe is lekker");

    printf("How many l's? %d\n", l_count);
    return 0;
}

int count_ls_in_string(char string[]) {


    // while string is not equal to l
    // keep looking for l

    // loop through the string
    //     keep loopoing until we find \0
    // if there is an l, increment some counter

    // lewe is lekker\0
    //                ^
    // pos = 8
    // character = string[pos] = /0

    int counter = 0;
    int pos = 0;

    char character = string[pos];
    while (character != '\0') {
            // You can do characters or numbers
        if (97 <= character && character <= 'z') {
            counter += 1;
        }
        pos++;
        character = string[pos];
    }

    return counter;
}








void print_capitalise_string(char * string) {
    // loop
    // stop on condition where char is a \0

    // Refer to ascii table to see the conversion

    int pos = 0;
    while (string[pos] != '\0') {
        printf("%4c", string[pos]);
        pos++;
    }
    printf("\n");

    pos = 0;
    while (string[pos] != '\0') {
        printf("%4d", string[pos]);
        pos++;
    }
    printf("\n");

    pos = 0;
    while (string[pos] != '\0') {
        printf("%4c", string[pos]-32);
        pos++;
    }
    printf("\n");
}

