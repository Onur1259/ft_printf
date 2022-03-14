#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_printstr(char *str)
{
    int i;

    i = 0;
    if(!str)
        return (ft_printstr("(null)"));
    while(str[i])
        i += ft_putchar(str[i]);
    return (i);
}


int control(va_list arg, char format)
{
    int     len;
    char    *a;

    len = 0;
    if (format == 'c')
        len += ft_putchar(va_arg(arg, int));
    else if (format == 's')
        len += ft_printstr(va_arg(arg, char *));
    else if (format == 'p') // * pointer argümanını hexadecimal biçiminde yazdırır
        len += ptr_(va_arg(arg,unsigned long));
    else if (format == 'u') // %u 10 tabanında işaretsiz decimal sayı yazdırır
        len += ft_uitoa(va_arg(arg, unsigned int));
    else if (format == 'x' || format == 'X')
        len += hex_system(va_arg(arg, unsigned int), format);
    else if (format == '%')
        len += ft_putchar('%');
    else if (format == 'd' || format == 'i')
    {
        a = ft_itoa(va_arg(arg, int));
        len += ft_printstr(a);
        free(a); 
    }
    return (len);
}

int ft_printf(const char *str, ...)
{
    va_list arg;
    int     i;
    int     len;

    va_start(arg, str);
    i = 0;
    len = 0;
    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            len += control(arg, str[i]);
        }
        else
            len += ft_putchar(str[i]);
        i++;
    }
    va_end(arg);
    return (len);
}
/*
int	main(void)
{
    char    len;

    len = 0;

    char c = 'a';
    char *s = "Onur Ozturk";
    int d = 53;
    unsigned int u = 2071;
    int x = 123;
    int X = 123;

    len += ft_printf("s= %s\n",s);
    len += ft_printf("c= %c\n",c);
    len += ft_printf("d= %d\n",d);
    len += ft_printf("x= %x\n",x);
    len += ft_printf("X= %X\n",X);
    len += ft_printf("u= %u\n",u);
    len += ft_printf("p= %p\n",32);
    len += ft_printf("%%\n");
    ft_printf("uzunluk: %d\n", len);
}
*/