#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 300


#include "tokenizing.h"

// Tokenizing: Break user's input strings into tokens using comma delimiter.
// E.g	Input:	The quick brown,fox jumps, over the, lazy dog.
//		Output:	Phrase #1 is 'The quick brown'
//				Phrase #2 is 'fox jumps'
//				Phrase #3 is ' over the'
//				Phrase #4 is ' lazy dog.'
void tokenizing(void) {

	// Diplay welcome message
	printf("*** Start of Tokenizing Words Demo  ***\n");

	// Variable declarations
	char phrases[BUFFER_SIZE];
	char* nextPhrase = NULL;
	int phrasesCounter;

	// Do while construct: Code block to keep user on performinng
	//	tokenizing demo in the application. This loop ends
	//	once user pressed the charact 'q' on the keyword therefore quitting the application.
	do {
		// Display program instruction
		printf("Type a few phrases separated by comma (q - to quit):\n");

		// Read line of text and assign to the variable words with buffer size of BUFFER_SIZE 300
		fgets(phrases, BUFFER_SIZE, stdin);

		// Statement to remove the NULL string ternmination.
		phrases[strlen(phrases) - 1] = '\0';
		//	else, the application perform the tokenization
		if (strcmp(phrases, "q") != 0) {

			// Get token values using the built in function strtok to get the splitted words from an input string using "," (comma delimiter) 
			nextPhrase = strtok(phrases, ",");
			phrasesCounter = 1;

			// Perform while construct to get each word (token) from the the splitted words
			while (nextPhrase)
			{
				//Print each token to the command line including the position of the phrase in ascending order
				printf("Phrase #%d is \'%s\'\n", phrasesCounter++, nextPhrase);
				//Set next word value to by getting the succeding tokens of the splitted words  (comma delimiter) 
				nextPhrase = strtok(NULL, ",");
			}
		}
	} while (strcmp(phrases, "q") != 0);

	// End of program display message
	printf("*** End of Tokenizing Words Demo ***\n\n");
}