#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 80 //whitebox testing
#define NUM_INPUT_SIZE 10
#include "fundamentals.h"



void clr(char* ptr)
{
	//This checks for the excess input in the buffer that the fgets didn't read
	if (strchr(ptr, '\n') == NULL)
	{
		while (getchar() != '\n')
		{
			;
		}
	}

}
void fundamentals(void)
{

	
	/* Version 2 */
	//>> insert here
	printf("*** Start of Measuring Strings Demo ***\n");

	//:::::::  Variables Declaration for V2
	char tmpbuffer2[BUFFER_SIZE + 1];
	char buffer2[BUFFER_SIZE + 2];
	//------- [  Variables Cunters and flag exit ]
	flagExit = 1; ctr = 0; flagChar = 0; spceCtr = 0; spceFlag = 0;

	//---------->>>>  Start of the V2 2 String Count Input Loop
	do
	{
		//Reset Variable Value
		ctr = 0; flagChar = 0; spceCtr = 0; spceFlag = 0; 



		//Reset the value of buffer2 to NULL for safe state
		for (ctr = 0;ctr < BUFFER_SIZE;ctr++)
		{
			buffer2[ctr] = '\0';
		}

		printf("Type a string (q - to quit):\n");
		fgets(tmpbuffer2, BUFFER_SIZE, stdin); //Gets the String Input from the User

		clr(tmpbuffer2);// Fix the buffer overflow by clearing the buffer

		if (tmpbuffer2[0] != '\n')   // Filter User Input for empty inpu or miss click of 'Enter Key'
		{
			tmpbuffer2[strlen(tmpbuffer2) - 1] = '\0'; // Set a Null Terminator for the user input variable
		// Filter user Input for space before the non Space character inputed
			while (spceFlag == 0)
			{
				if (tmpbuffer2[spceCtr] == ' ')
				{
					spceCtr++; // To count the space in the front of the input
				}
				else
				{
					spceFlag = 1;
				}
			}
			//To check if there is a Non Space character after all space character inputted first from the User Input and if it's not a NULL
			if (tmpbuffer2[spceCtr] != '\0') // Use spceCtr value as the starting index
			{
				for (ctr = spceCtr;tmpbuffer2[ctr] != '\0';ctr++) //  transfering value loop
				{

					buffer2[ctr - spceCtr] = tmpbuffer2[ctr]; // Transfering value from tmpbuffer2 -> buffer2 
				}
				buffer2[strlen(tmpbuffer2)] = '\0'; // Setting Null Terminator for the last index of the buffer2
				if (strcmp(buffer2, "q") != 0)// validate input if it's not 'q'
				{ // Fix: There is none in Version 2.0
					printf("The legth of \'%s\' is %d characters\n", buffer2, (int)strlen(buffer2)); // It will display the number of characters on the string by using the function strlen();
				} // FIX:
			}
			else
			{
				printf("Error: Input string is empty!!\n"); // Error Message if the user Input Space and 'Enter Key'
			}
		}
		else
		{
			printf("Error: Input string is empty!!\n"); // Error Message if the user press 'Enter Key' wihtout putting anything
		}

	} while (strcmp(buffer2, "q") != 0);// Condition to be met to exit

	printf("*** End of Measuring Strings Demo ***\n");


	/* Version 3 */
	//>> insert here

}