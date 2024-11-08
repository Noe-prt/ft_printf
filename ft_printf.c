#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	char	type;

	va_start(args, str);
	i = 0;
	type = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			type = str[i + 1];
			put_format(args, type);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (0);
}

void	put_format(va_list args, char type)
{
	if (type == INT_SYMBOL)
		ft_putnbr_fd((int) va_arg(args, int), 1);
	else if (type == C_SYMBOL)
		ft_putchar_fd((int) va_arg(args, int), 1);
	else if (type == STR_SYMBOL)
		ft_putstr_fd((const char *) va_arg(args, const char *), 1);
	else if (type == '%')
		ft_putchar_fd(type, 1);
	else if (type == 'p')
		ft_putptr((void *) va_arg(args, void *));
}

int	is_type(char c)
{
	while (*types)
	{
		if (*types == c)
			return (1);
	}
	return (0);
}

void ft_puthex(unsigned long num)
{
	if (num >= 16)
		ft_puthex(num / 16);
	ft_putchar_fd("0123456789abcdef"[num % 16], 1);
}

void ft_putptr(void *ptr)
{
	unsigned long	adress;

	adress = (unsigned long) ptr;
	ft_putstr_fd("0x", 1);
	ft_puthex(adress);
}

#include <stdio.h>

int	main(void)
{
	const char	s1[] = "BONJOUR";
	const char	s2[] = "SALUT";
	int		nb = 456;
	int	*ptr = &nb;
	ft_printf("Ceci est une phrase %% : %s, %s, %d, adress : %p", s1, s2, nb, ptr);
	return (0);
}
