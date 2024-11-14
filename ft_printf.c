#include "ft_printf.h"

int	sorting_hat(const char *s, va_list args)
{
	if (*s == 'c')
		return (print_char(va_arg(args, int)));
	else if (*s == 'i' || *s == 'd')
		return (putnbr_count(va_arg(args, int)));
	else if (*s == 's')
		return (put_str_count(va_arg(args, char *)));
	else if (*s == 'u')
		return (print_usnigned(va_arg(args, unsigned int)));
	else if (*s == 'x')
		return (hexa_lower(va_arg(args, int)));
	else if (*s == 'X')
		return (hexa_upper(va_arg(args, int)));
	return (-1);
}

int ft_printf(const char *s, ...)
{
	va_list	args;
	int count;
	int	i;
	int	temp;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		temp = ft_printf_normal(&s[i]);
		if (temp == -1)
			return (-1);
		i += temp;
		if (s[i] == '%')
		{
			count += sorting_hat(&s[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	count += (strlen_count(s));
	return (count);
}