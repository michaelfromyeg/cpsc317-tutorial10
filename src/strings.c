#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void strings_example()
{
    // strings
    // declaring strings
    char c = 0x77;
    char *string1 = "Hello, world!";
    char string2[] = "Hello, world!";
    char *string3 = malloc(sizeof(char) * (strlen(string1) + 1));

    size_t i;
    for (i = 0; i < strlen(string1); i++)
    {
        string3[i] = string1[i];
    }
    string3[strlen(string1)] = '\0';

    printf("c=%c\n", c);
    printf("string1=%s\n", string1);
    printf("string2=%s\n", string2);
    printf("string3=%s\n", string3);

    printf("\n");
}

void strlen_example()
{
    char *string1 = "Hello, world!";
    char string2[] = "Hello, world!";
    char *string3 = malloc(sizeof(char) * (strlen(string1) + 1));

    size_t i;
    for (i = 0; i < strlen(string1); i++)
    {
        string3[i] = string1[i];
    }
    string3[strlen(string1)] = '\0';

    // strlen
    // get the length of the string, without the null ('\0')
    printf("strlen(string1)=%ld\n", strlen(string1));
    printf("strlen(string2)=%ld\n", strlen(string2));
    printf("strlen(string3)=%ld\n", strlen(string3));

    printf("\n");
}

void snprintf_example()
{
    char *string1 = "Hello, world!";

    // snprintf
    // format a string and write into a buffer
    // see also: sprintf, a simpler version of this method
    char buffer[20];

    int n = 6 + strlen("format=");
    int retval = snprintf(buffer, n, "format=%s\n", string1);
    printf("string written on buffer = %s\n", buffer);
    printf("value returned by snprintf() method = %d\n", retval);

    printf("\n");
}

void strcmp_example()
{
    char *string1 = "Hello, world!";
    char string2[] = "Hello, world!";

    // strcmp
    // compare two strings; 0 if equal, >0 if left has greater ASCII (i.e., lexicographically after), <0 if left has lesser ASCII (i.e., lexicographically before)
    int cmp = strcmp(string1, string2);
    printf("cmp=%d\n", cmp);

    printf("\n");

    // exercise ... look at strcasecmp
}

void strtol_example()
{
    // strtol; networking equivalents (XtoY is a common pattern in C, e.g., atoi)
    // convert a string to a number
    long int li = strtol("123", NULL, 10);
    printf("li=%ld\n", li);

    printf("\n");
}

void strtok_example()
{
    // strtok
    // string split in C

    char str1[80] = "This is - cs.ubc.ca - a website";
    const char s[2] = "-";

    char *token;
    token = strtok(str1, s);

    while (token != NULL)
    {
        printf(" %s\n", token);
        token = strtok(NULL, s);
    }
    printf("mutated: %s\n", str1);
}

void strtok_example2()
{
    // strtok - harder example
    char str2[] = "- This,      ---     a sample string.";

    char *pch;
    printf("Splitting string \"%s\" into tokens:\n", str2);
    pch = strtok(str2, " ,.-");

    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
    }

    printf("mutated: %s\n", str2);

    pch = strtok(str2, "- ");
    printf("%s\n", pch);

    // you can change delimiters at any time
    pch = strtok(pch, "i");
    printf("%s\n", pch);

    printf("\n");
}

int main()
{
    strings_example();
    // strlen_example();
    // snprintf_example();
    // strcmp_example();
    // strtol_example();
    // strtok_example();
    // strtok_example2();
}
