/*
* Filename:	main.c
* Date:		13/11/2024
* Name:		EL Joubert
*
* Print out a grid of stars in various different patterns
* Take input from the user to figure out how big the grid must be
*/
#include <stdio.h>
#include <stdlib.h>

#include "draw_stars.h"

int main()
{

	// Step 1: How to print out one line of stars, length specified by user?
	// Take input from user, how may stars to print?
	// Print out that many stars

	// Step 2: How could we make patterns in the one line? e.g. alternating space and *
	// Step 3: How do we repeat the printing of one line to draw a grid?
	// Step 4: How can we do different patterns in the grid?
    // Step 5: Can we extract different patterns into different functions?
    int grid_size;
	printf("How big is the grid you would like to print?\n");
	//scanf("%d", &grid_size);

    grid_size = 30;

    draw_cross(grid_size);
    draw_circle(20, 8);




	// Step 6: Can we extract those functions into a header file?
    return 0;
}


