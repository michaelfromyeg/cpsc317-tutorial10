#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    // ...
} DAY;

const static struct
{
    DAY val;
    const char *str;
} conversion[] = {
    {MONDAY, "monday"},
    {TUESDAY, "tuesday"},
    {WEDNESDAY, "wednesday"},
    // ...
};

DAY str2enum(const char *str)
{
    size_t i;
    for (i = 0; i < sizeof(conversion) / sizeof(conversion[0]); ++i)
        if (!strcmp(str, conversion[i].str))
            return conversion[i].val;
    printf("no such string %s\n", str);
}

int main()
{
    DAY d1 = str2enum("monday");
    printf("d1.val=%d\n", d1);

    DAY d2 = str2enum("tuesday");
    printf("d2.val=%d\n", d2);
}
