/*
* Filename:	main.c
* Date:		12/11/2024
* Name:		EL Joubert
*
* Program to showcase how each operator works
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

	// Printing special characters came up in 2013
	/* \n Newline. Position the cursor at the beginning of the next line. */
	printf("Some\n words\n seperated \n by\n newlines\n");

	/* \t Horizontal tab. Move the cursor to the next tab stop. */
	printf("\tOffset by a tabspace\n");

	/* \a Alert. Sound the system bell. */
	printf("Make a sound: \a\n");

	/* \\ Backslash. Insert a backslash character in a string. */
	/* \" Double quote. Insert a double quote character in a string. */
	/* \’ Single quote. Insert a single quote into string. */
	printf("Put \"qoutes\" inside a 'print', or even \\backslashes\\ \n");

	/* \r Position the cursor at the beginning of the current line. */
	printf("\nWe can also reset the cursor to the start of the line\n");
	printf("We can also reset the cursor to the start of \rthe line\n");

	int x;
	// Arithmetic operators
	// *	Multiply
	// /	Divide
	// - 	Subtract
	// + 	Add
	// %	Mod (get remainder)

	// Operate and assign
	// *=, /=, -=, +=, %=

	int a = 2;
	int b = 3;

	a = a * b;
	a *= b;

	// -- Decrement (minus 1)
	// ++ Increment (plus 1)
	// There is a difference whether it becomes before or after
	// Here is a good site that explains it:
	// https://www.geeksforgeeks.org/arithmetic-operators-in-c/

    a--;
    a = a - 1;
    ++b;
    b = b + 1;

	x = 5;
	printf("\nDecrement before: %d\n", --x);

	x = 5;
	printf("Decrement after: %d\n", x--);
	 // do -- after
	//x = 4


	int w = 3;
	while (w > 0) {
        printf("w: %d\n", w--);
	}

	// Same as
	while (w > 0) {
        printf("w: %d\n", w);
        w -= 1;
	}

	printf("\n");
    w=3;
	while (w > 0) {
        w -= 1;
        printf("w: %d\n", w);
	}

	return 0;
}
