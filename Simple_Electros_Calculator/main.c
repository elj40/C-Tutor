/*
* Filename:	main.c
* Date:		12/11/2024 
* Name:		EL Joubert
*
* Just a simple calculator to using V = IR to calculate some values
* Will showcase functions, if else statements, switch cases, user input and
* basic data types
*/
#include <stdio.h>
#include <stdlib.h>

// Make these constant ints, so our code is more clear and less likely
// to break later
#define VOLTAGE 1
#define CURRENT 2
#define RESISTANCE 3
#define MAX_POWER 4

void calculate_current();
float calculate_resistance(float V, float I);
float calculate_max_power(float V, float R); //TODO: implement this function

int main()
{
	
	float voltage;
	float current;
	float resistance;
	int option;

	printf("Hello! What would you like to calculate?\n");
	printf("1. Voltage\n");
	printf("2. Current\n");
	printf("3. Resistance\n");
	printf("4. Max Power (for you to implent)\n");
	scanf("%d", &option);
	//	    ^		The & character is pretty important because scanf accepts a pointer

	//////////////////////////////////////////////////////////////////////////////
	//TODO: handle the case for it the user decides to choose to calculate max power
	//Use the formula P_max = (V*V)/(4*R)
	switch (option) {
		case VOLTAGE:
			///////////////////////////////////////////////
			// TODO: extract this out into its own function
			printf("Enter the amount of current (A): ");
			scanf("%f", &current);
			printf("Enter the amount of resistance (Ohm): ");
			scanf("%f", &resistance);
			
			voltage = current * resistance;
			printf("Voltage (V): %f\n", voltage);
			break;
		case CURRENT:
			//Here, similar code to above has been extracted into a function
			calculate_current();
			break;
		case RESISTANCE:
			printf("Enter the amount of voltage (V): ");
			scanf("%f", &voltage);
			printf("Enter the amount of current (A): ");
			scanf("%f", &current);

			resistance = calculate_resistance(voltage, current);
			if (resistance != -1.0) {
				printf("Resistance (Ohm): %f\n", resistance);
			}
			break;
		default:
			printf("This message prints if you did not select one of the available options\n");
			break;
			
	}

	return 0;
}

float calculate_resistance(float V, float I) {
	float R;
	if (I == 0) 
	{
		printf("When I = 0, resistance is infinite so it is an open circuit\n");
		return -1;
	} else 
	{
		R = V / I;
		if (R < 0) 
		{
			return -R;
		} else
		{
			return R;
		}
	}
}

void calculate_current() 
{
	float local_voltage;
	float local_resistance;
	float local_current;

	printf("Enter the amount of voltage (V): ");
	scanf("%f", &local_voltage);
	printf("Enter the amount of resistance (Ohm): ");
	scanf("%f", &local_resistance);

	if (local_resistance == 0) {
		printf("Divide by zero error, resistance must not be zero\n");
	} else if (local_resistance < 0) {
		printf("Silly goose.. negative resistance doesn't make sense\n");
	} else {
		local_current = local_voltage / local_resistance; 
		printf("Current (A): %f\n", local_current);
	}

}
