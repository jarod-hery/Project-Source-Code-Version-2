
//Version 2

#define _CRT_SECURE_NO_WARNINGS // Disable warnings for non-secure functions in MSVC
#define BUFFER_SIZE 80 // Define a constant for buffer size to avoid magic numbers
#include "manipulating.h"



#include <ctype.h>


int isHexEscape(const char* seq) {
    if (seq[0] != '\\' || seq[1] != 'x') return 0;
    char hi = seq[2];
    char lo = seq[3];
    return isxdigit(hi) && isxdigit(lo);
}

int containsInvalidSequences(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (iscntrl((unsigned char)str[i]) && str[i] != '\n') {
            return 1;
        }
        if (str[i] == '\\' && str[i + 1] == 'x' && isHexEscape(str + i)) {
            return 1;
        }
    }
    return 0;
}

void manipulating(void) {
    printf("*** Start of Concatenating Strings Demo ***\n");
    char string1[BUFFER_SIZE], string2[BUFFER_SIZE];

    do {
        printf("Type the 1st string (q - to quit):\n");
        fgets(string1, BUFFER_SIZE, stdin);
        string1[strcspn(string1, "\n")] = '\0';

        if (containsInvalidSequences(string1)) {
            printf("Error: String1 contains control characters or invalid escape sequences.\n");
            continue;
        }

        // Check if string1 has already reached or exceeded the limit
        if (strlen(string1) >= BUFFER_SIZE - 1) {
            printf("Error: String1 reached or exceeded the buffer limit. Cannot add more characters.\n");
            continue;
        }

        if (strcmp(string1, "q") == 0) break;

        printf("Type the 2nd string:\n");
        fgets(string2, BUFFER_SIZE, stdin);
        string2[strcspn(string2, "\n")] = '\0';
        if (containsInvalidSequences(string2)) {
            printf("Error: String2 contains control characters or invalid escape sequences.\n");
            continue;
        }

        if (strlen(string1) + strlen(string2) < BUFFER_SIZE) {
            strcat(string1, string2);
            printf("Concatenated string is '%s'\n", string1);
        }
        else {
            printf("Error: Concatenation would exceed buffer size.\n");
        }
    } while (1);

    printf("*** End of Concatenating Strings Demo ***\n");
}
