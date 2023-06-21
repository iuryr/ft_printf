/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:10:55 by iusantos          #+#    #+#             */
/*   Updated: 2023/06/21 16:21:50 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	prtf_putstr(char *str)
{
	size_t length;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (length);
}

size_t print_int(int nbr)
{
	size_t	length;
	char	*str;

	str = ft_itoa(nbr);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}

static size_t	digit_counter(long n)
{
	size_t	counter;

	counter = 1;
	while (n / 10 != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

static void	str_writer(long n, char *str, size_t length)
{
	size_t	index;

	index = length;
	str[index] = '\0';
	index--;
	while (n / 10 != 0)
	{
		str[index] = (n % 10) + 48;
		index--;
		n = n / 10;
	}
	str[index] = (n % 10) + 48;
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	length;

	length = digit_counter(n);
	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str_writer(n, str, length);
	return (str);
}

size_t print_uint(unsigned int nbr)
{
	size_t	length;
	char	*str;

	str = ft_uitoa(nbr);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}

size_t	hex_digit_counter(unsigned long n)
{
	size_t	counter;

	counter = 1;
	while (n / 16 != 0)
	{
		counter++;
		n = n / 16;
	}
	return (counter);
}

void	hex_str_writer(unsigned long n, char *str, size_t length, char c)
{
	size_t	index;
	char	base[17];

	if (c == 'l')
		ft_memcpy(base, "0123456789abcdef", 17);
	if (c == 'u')
		ft_memcpy(base, "0123456789ABCDEF", 17);
	index = length;
	str[index] = '\0';
	index--;
	while (n / 16 != 0)
	{
		str[index] = base[n % 16];
		index--;
		n = n / 16;
	}
	str[index] = base[n % 16];
}

char	*uitohex(unsigned long n, char c)
{
	char	*str;
	size_t	length;

	length = hex_digit_counter(n);
	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	hex_str_writer(n, str, length, c);
	return (str);
}


size_t	print_hex(unsigned long n, char c)
{
	size_t	length;
	char	*str;

	str = uitohex(n, c);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return(length);
}

void	pref_hex_str_writer(unsigned long n, char *str, size_t length)
{
	size_t	index;
	char	base[17];

	ft_memcpy(base, "0123456789abcedf", 17);
	index = length;
	str[index] = '\0';
	index--;
	while (n / 16 != 0)
	{
		str[index] = base[n % 16];
		index--;
		n = n / 16;
	}
	str[index--] = base[n % 16];
	str[index--] = 'x';
	str[index] = '0';
}

char	*ultoa(unsigned long n)
{
	char	*str;
	size_t	length;

	length = hex_digit_counter(n);
	str = malloc((length + 3) * sizeof(char));
	if (str == NULL)
		return (NULL);
	pref_hex_str_writer(n, str, length + 2);
	return (str);
}

size_t	print_voidp(void *p)
{
	size_t	length;
	char *str;

	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	str = ultoa((unsigned long) p);
	length = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (length);
}
