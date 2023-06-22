/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:54:04 by iusantos          #+#    #+#             */
/*   Updated: 2023/06/22 15:01:04 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (format[index + 1] == 'x')
				ret_len += print_hex(va_arg(args, unsigned int), 'l') -1;
			if (format[index + 1] == 'X')
				ret_len += print_hex(va_arg(args, unsigned int), 'u') -1;
			if (format[index + 1] == 'p')
				ret_len += print_voidp(va_arg(args, void *)) -1;
			if (format[index + 1] == '%')
				ft_putchar_fd('%', 1);
			index++;
		}
		else
			ft_putchar_fd(format[index], 1);
		index++;
	}
	va_end(args);
	return (ret_len);
}

