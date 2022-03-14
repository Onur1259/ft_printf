#include "ft_printf.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char    *ft_strdup(const char *str)
{
    char    *temp;
    int     i;
    size_t  len;

    i = 0;
    len = ft_strlen(str);
    temp = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (0);
    while(str[i])
    {
        temp[i] = str[i];
        i++;
    }
    temp[i] = '\0';
    return(temp);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;

    i = 0;
    if (size > 0)
    {
        while(src[i] && i < (size - 1))
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = 0;
    }
    while(src[i])
        i++;
    return (i);
}
