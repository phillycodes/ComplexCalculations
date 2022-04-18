/*
 * File Name:		Calculating_More.c
 * Names:			Philben Pierre
 * Course:			COP 2220C at Valencia College
 * Professor:		David Stendel
 * Description:		The first thing to show up in the program is a calculator menu. The menu has 9
 *					options to choose from. Enter Values, add, subtract, multiply, divide, 
 *					average, maximum value an option to determine whether each value entered is 
 *					positive, negative or zero, and a quit option. 
 *					The program presents the menu and requests for an input from the user. 
 *					If the user enter an input that is not prompted in the menu then
 *					an error message will pop-up informing the user that they had entered an
 *					invalid entry. The program allows the user to try again. For a few of the
 *					options the user cannot select them without first selecting "Enter Values".
 *					If the user tries to do so without entering the values then an error message
 *					will pop up saying that they have not entered any values. The user can chose as
 *					they please until they select 'Q' for quit. After doing so thet will be thanked
 *					for using the application. 
 * Date:			3/12/21
 */

 // Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define SIZE 3

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		The first thing to show up in the function is a calculator menu. The menu has 9
 *					options to choose from. Enter Values, add, subtract, multiply, divide, 
 *					average, maximum value an option to determine whether each value entered is 
 *					positive, negative or zero, and a quit option. 
 *					The function presents the menu and requests for an input from the keyboard. 
 *					If the user enter an input that is not prompted in the menu then
 *					an error message will pop-up informing the user that they had entered an
 *					invalid entry. The function has a loop to try again. For a few of the
 *					cases the user cannot select them without first selecting "Enter Values".
 *					If the user tries to do so without entering the values then an error message
 *					will pop up saying that they have not entered any values. The user can chose as
 *					they please until they select 'Q' for quit. After doing so thet will be thanked
 *					for using the application. 
 * Return Value:	An integer representing an error code; if the program ends without error, zero
 *					will be returned to the calling program or operating system.
 */


int main() {
	// Variables
	double result = 0.0;
	char menuSelect = '\0';
	double numbers[SIZE] = { 0.0 };
	bool valuesEntered = false;
	bool foundZero = false;
	int i, count;

	// Output Selection Menu
	do {
		result = 0;
		// Input Selection Menu
		printf("Calulator Menu\n\n");
		printf("(E)nter Values\n");
		printf("(A)dd\n");
		printf("(S)ubtract\n");
		printf("(M)ultiply\n");
		printf("(D)ivide\n");
		printf("A(V)erage\n");
		printf("Ma(X)imum Value\n");
		printf("(P)ositive, Negative, or Zero\n");
		printf("(Q)uit\n");
		printf("Enter Selection: ");
		scanf_s(" %c", &menuSelect, 1);

			// Menu Processing
		switch (menuSelect) {
			// Getting Numbers
			case 'e':
			case 'E':
				// Output - Requesting Input 
				printf("Enter %i numbers separated with a space: ", SIZE);
				for (i = 0; i < SIZE; i++) {
					scanf_s("%lf", &numbers[i]);
				}

				// Some Operations Require Values To Be Entered
				valuesEntered = true;
				break;
			// Addition
			case 'a':
			case 'A':
				if (valuesEntered == true) {
					// Calculations 
					result = numbers[0];
					for (i = 1; i < SIZE; i++) {
						result += numbers[i];
					}

					// Output
					for (i = 0; i < SIZE - 1; i++) {
						printf("%.3f + ", numbers[i]);
					}
					printf("%.3f = %.3f\n", numbers[i], result);
				} else {
					printf("\n\tError: You have not entered %i numbers!\n\n", SIZE);
				}
				break;
			// Subtraction
			case 's':
			case 'S':
				if (valuesEntered == true) {
					// Calculations
					result = numbers[0];
					for (i = 1; i < SIZE; i++) {
						result -= numbers[i];
					}

					// Output
					for (i = 0; i < SIZE - 1; i++) {
						printf("%.3f - ", numbers[i]);
					}
					printf("%.3f = %.3f\n", numbers[i], result);
				} else {
					printf("\n\tError: You have not entered %i numbers!\n\n", SIZE);
				}
				break;
			// Multiplication
			case 'm':
			case 'M':
				if (valuesEntered == true) {
					// Calculations
					result = numbers[0];
					for (i = 1; i < SIZE; i++) {
						result *= numbers[i];
					}

					// Output
					for (i = 0; i < SIZE - 1; i++) {
						printf("%.3f * ", numbers[i]);
					}
					printf("%.3f = %.3f\n", numbers[i], result);
				} else {
					printf("\n\tError: You have not entered %i numbers!\n\n", SIZE);
				}
				break;
			// Division
			case 'd':
			case 'D':
				if (valuesEntered == true) {
					// Validation - Checking For Zero After The First Value
					for (i = 1; foundZero != true || i < SIZE; i++) {
						if (numbers[i] == 0.0) {
							foundZero = true;
						}
					}

					// Validation - Are Zero's Present In The Array After The First Value
					if (foundZero == true) {
						printf("\n\tError: You cannot divide by zero!\n\n");
					} else {
					// Calculations
						result = numbers[0];
						for (i = 1; i < SIZE; i++) {
							result /= numbers[i];
						}

						// Output
						for (i = 0; i < SIZE - 1; i++) {
							printf("%.3f / ", numbers[i]);
						}
						printf("%.3f = %.3f\n", numbers[i], result);
					}
				} else {
					printf("\n\tError: You have not entered %i numbers!\n\n", SIZE);
				}
				break;
			// Average
			case 'v':
			case 'V':
				if (valuesEntered == true) {
					// Calculations
					result = numbers[0];
					count = 1;
					for (i = 1; i < SIZE; ++i) {
						result += numbers[i];
						count++;
					}
					result = result / count;

					// Output
					printf("(");
					for (i = 0; i < SIZE - 1; i++) {
						printf("%.3f + ", numbers[i]);
					}
					printf("%.3f ) / %i = %.3f\n", numbers[i], SIZE, result);
				} else {
					printf("\n\tError: You have not entered %i numbers!\n\n", SIZE);

				}
				break;
			// Maximum Value
			case 'x':
			case 'X':
				// Determination
				result = numbers[0];
				for (i = 1; i < SIZE; i++) {
					if (numbers[i] > result) {
						result = numbers[i];
					}
				}

				// Output
				printf("Max Value: %.3f\n", result);
				break;
			// Positive, Negative, or Zero
			case 'p':
			case 'P':
				if (valuesEntered == true) {
					// Determination and Output
					for (i = 0; i < SIZE; i++) {
						// Validation - Negative
						if (numbers[i] < 0.0) {
							printf("%.3f is NEGATIVE\n", numbers[i]);

						// Validation - Positive
						} else if (numbers[i] > 0.0) {
							printf("%.3f is POSITIVE\n", numbers[i]);

						// Determination - Value is Zero
						} else {
							printf("%.3f is ZERO\n", numbers[i]);
						}
					}
				} else {
					printf("\n\tError: You have not entered %i numbers!\n\n", SIZE);
				}
				break;
			// Quit
			case 'q':
			case 'Q':
				// Outout
				printf("Good-Bye! Thanks for using my program!\n");
				break;
			// Invalid Input 
			default:
				// Output
				printf("\n\tError: You have entered an invalid input!\n\n");
		}

	} while (menuSelect != 'q' && menuSelect != 'Q'); // Loop Until The User Enters Q

	return 0;
}

