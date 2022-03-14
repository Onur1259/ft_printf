#include "ft_printf.h"


int hex_system(unsigned int n, char c)
{
    int         i;
    char        *a;
    unsigned int j;

    if (n == 0)
        return (write(1,"0",1));
    if (c == 'x')
        a = "0123456789abcdef";
    else
        a = "0123456789ABCDEF";
    j = n;
    i = 0;
    while (j > 0 && ++i)
        j = j / 16;
    if (n >= 16)
    {
        hex_system(n / 16, c);
        hex_system(n % 16, c);
    }
    else
        ft_putchar(a[n]);
    return (i);
}

int ptr_(unsigned long n)
{
    int i;

    i = 1;
    ft_putchar('0');
    ft_putchar('x');
    ptryaz(n);
    while (n >= 16)
    {
        n = n / 16;
        i++;
    }
    return (i + 2);
    
}

int ptryaz(unsigned long n)
{
    char    *a;

    a = ft_strdup("0123456789abcdef");
    if (n >= 16)
    {
        ptryaz(n / 16);
        ptryaz(n % 16);
    }
    else
        ft_putchar(a[n]);
    free(a);
    return (0);
}

/*#include <stdio.h>
int main()
{
    int i = hex_system(16,'x');
    int j = printf("\n%x",16);
    printf("i : %d, j :%d",i,j);
}*/