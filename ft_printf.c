#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	index;
	size_t	ret_len;
	va_list	args;

	ret_len = ft_strlen(format);
	va_start(args, format);
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			ret_len--;
			if (format[index + 1] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			if (format[index + 1] == 's')
				ret_len += prtf_putstr(va_arg(args, char *)) - 1;
			if (format[index + 1] == 'i' || format[index + 1] == 'd')
				ret_len += print_int(va_arg(args, int)) - 1;
			if (format[index + 1] == 'u')
				ret_len += print_uint(va_arg(args, unsigned int)) - 1;
			// if (format[index + 1] == 'x')
				// ret_len +=
			index++;
		}
		else
		{
			ft_putchar_fd(format[index], 1);
		}
		index++;
	}
	va_end(args);
	return (ret_len);
}

