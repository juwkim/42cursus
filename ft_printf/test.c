#include <stdio.h>
#include <string.h>
#include <limits.h>

int		ft_printf(const char *format, ...);
int main()
{
    int a = printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
    int b = ft_printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
    printf("ans: %d\n", a);
    printf("my : %d\n", b);
}