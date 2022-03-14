#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_putchar(char c);
int ft_printstr(char *str);
int control(va_list arg, char format);
int ft_printf(const char *str, ...);
char    *ft_strdup(const char *str);
char    *ft_strdup(const char *str);
size_t  ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
int ptryaz(unsigned long n);
int ptr_(unsigned long n);
int ft_uitoa(unsigned int n);
int basamak_say(unsigned int sayi);
char    *ft_itoa(int n);
int nbr_len(int nbr);
int hex_system(unsigned int n, char c);

# endif