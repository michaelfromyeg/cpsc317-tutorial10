#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1024];

    while (1)
    {
        printf("Enter string: ");
        fgets(str, sizeof str, stdin);
        str[strcspn(str, "\n")] = '\0';

        /**
         * TODO: Implement a function that takes in user input until “quit” is entered (case insensitive), afterwhich it returns out of the function
         * For non-quit inputs, tokenize by the space character, print out each token, and print out the # of token, e.g.,
         *
         * $ Enter string: one two three four
         * > one
         * > two
         * > three
         * > four
         * > 4
         * $ Enter string: quit
         *
         */
    }
}
