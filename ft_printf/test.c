#include <stdio.h>
#include <stdarg.h>

#include <stdio.h>

void testit (int i, ...)
{
    va_list argptr;
    va_start(argptr, i);

    if (i == 0)
    {
        int n = va_arg(argptr, unsigned long long);
        printf("%d\n", n);
    }
    else
    {
        char *s = va_arg(argptr, char*);
        printf("%s\n", s);
    }

    va_end(argptr);
}

int main()
{
    printf("asdasd");
    testit(0, 2147483648); // 1st problem: 0xffffffff is not an int
    testit(1, (void *)(0));       // 2nd problem: NULL is not a char*
}