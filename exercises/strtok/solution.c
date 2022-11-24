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

        if (strcasecmp(str, "QUIT") == 0)
        {
            break;
        }

        char dup[1024];
        strcpy(dup, str);
        char *tok;
        tok = strtok(dup, " ");
        int acc = 0;
        while (tok != NULL)
        {
            printf("%s\n", tok);
            tok = strtok(NULL, " ");
            acc++;
        }
        printf("%i\n", acc);
    }
}
