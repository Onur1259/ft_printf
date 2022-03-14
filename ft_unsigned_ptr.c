#include "ft_printf.h"

int basamak_say(unsigned int sayi)
{
    int i;

    i = 0;
    while(sayi >= 10)
    {
        sayi = sayi / 10;
        i++;
    }
    return (i + 1);
}

int ft_uitoa(unsigned int n)
{
    int     len;
    char    *str;
    
    len = basamak_say(n);
    str = (char *)malloc(sizeof(char) * len + 1);
    str[len] = '\0';
    while (len > 0)
    {
        str[len - 1] = n % 10 + '0';
        n = n / 10;
        len--;
    }
    len = ft_printstr(str);
    free(str);
    return (len);
}

int get_len(int nbr)
{
    int len;

    len = 0;
    if (nbr <= 0)
        len++;
    while(nbr)
    {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    int     digit;
    char    *str;

    digit = get_len(n);
    str = (char *)calloc(sizeof(char), digit + 1);
    if (!str)
        return (NULL);
    if (n == 0)
        *str = '0';
    else if (n < 0)
    {
        if (n == -2147483648)
        {
            ft_strlcpy(str,"-2147483648\0",digit + 1);
            return (str);
        }
        str[0] = '-';
        n = n * -1;
    }
    while (n != 0)
    {
        *(str + --digit) = (n % 10) + '0';
        n = n / 10;
    }
    return (str);
}