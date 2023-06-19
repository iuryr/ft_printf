#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	index;
	va_list	args;

	va_start(args, format);

	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index+1] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), 1);
			index++;
		}
		if (format[index] == '%' && format[index + 1] == 's')
		{
			ft_putstr_fd(va_arg(args, char *), 1);
			index++;
		}
		if (format[index] == '%' && format[index + 1] == 'i')
		{
			ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
			index ++;
		}
		else
		{
			ft_putchar_fd(format[index], 1);
		}
		index++;
	}
	va_end(args);
	return (0);
}

