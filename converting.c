#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // For LONG_MIN, LONG_MAX
#include <errno.h> // For errno (used for error reporting)
#define BUFFER_SIZE 80

/* Version 2 */

void converting(void) {
    printf("*** Start of Converting Strings to double Demo ***\n");
    char doubleString[BUFFER_SIZE]; // Define a character array to store the input string
    double doubleNumber; // Declare a variable to store the converted double
    char* endPtr; // Declare a pointer to store the end of the converted string

    do {
        printf("Type the double numeric string (q - to quit):\n");
        fgets(doubleString, BUFFER_SIZE, stdin); // Read input string from standard input

        // Check if the input exceeds buffer size
        if (strlen(doubleString) == BUFFER_SIZE - 1 && doubleString[BUFFER_SIZE - 2] != '\n')
        {
            printf("Input string too long. Please enter a shorter string.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue; // Continue to the next iteration of the loop
        }

        doubleString[strcspn(doubleString, "\n")] = '\0'; // Remove trailing newline

        if (strcmp(doubleString, "q") != 0)
        { // Check if input is not "q" (to quit)
            // Check if the input contains a decimal point
            if (strchr(doubleString, '.') == NULL)
            {
                printf("Invalid input. Please enter a numeric string with a decimal point.\n");
                continue; // Continue to the next iteration of the loop
            }

            doubleNumber = strtod(doubleString, &endPtr); // Convert input string to double

            // Check if conversion failed or there are extra characters after the number
            if (endPtr == doubleString || *endPtr != '\0')
            {
                printf("Invalid input. Please enter a valid numeric string.\n");
            }
            else
            {
                // Check the length of the string representation of the fractional part
                char* dotPtr = strchr(doubleString, '.'); // Find the decimal point in the input string
                if (dotPtr != NULL && strlen(dotPtr + 1) > 6)
                { // If there are more than 6 digits after the decimal point
                    printf("Error: Too many decimal places. Please enter a number with fewer decimal places.\n");
                }
                else
                {
                    printf("Converted number is %lf\n", doubleNumber);
                }
            }
        }
    } while (strcmp(doubleString, "q") != 0); // Repeat the loop until user inputs "q" to quit

    printf("*** End of Converting Strings to double Demo ***\n\n");
}

