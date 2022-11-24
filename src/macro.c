#include <stdio.h>

// #define DEBUG

#ifdef DEBUG
#define _DEBUG(fmt, args...) printf("%s:%s:%d: " fmt, __FILE__, __FUNCTION__, __LINE__, args)
#else
#define _DEBUG(fmt, args...)
#endif

int main()
{
    int x = 3;
    _DEBUG("This is my debug statement, x=%d\n", x);
    printf("This is my non-debug statement, x=%d\n", x);
}
