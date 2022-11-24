#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
    MONDAY,
    TUESDAY,
    // ...
} DAY;

const static struct
{
    DAY val;
    const char *str;
} conversion[] = {
    {MONDAY, "monday"},
    {TUESDAY, "tuesday"},
    // ...
};

DAY str2enum(const char *str)
{
    /**
     * TODO: add the missing days, and convert the given string value into an enum using the conversion table
     *
     * Hint: strcmp will help!
     */

    return MONDAY;
}

int main()
{
    DAY d1 = str2enum("monday");
    printf("d1.val=%d\n", d1);

    DAY d2 = str2enum("tuesday");
    printf("d2.val=%d\n", d2);
}
