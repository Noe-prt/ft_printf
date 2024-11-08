#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

#define INT_SYMBOL 'd'
#define C_SYMBOL 'c'
#define STR_SYMBOL 's'

const char	types[] = {INT_SYMBOL, C_SYMBOL, STR_SYMBOL};

int     ft_printf(const char *str, ...);
int     is_type(char c);
void    put_format(va_list args, char type);
void	ft_putchar_fd(char c, int fd);
int	ft_strlen(const char *str);
void		ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void ft_puthex(unsigned long num);
void ft_putptr(void *ptr);

#endif


