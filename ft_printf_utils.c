/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:10:55 by iusantos          #+#    #+#             */
/*   Updated: 2023/06/20 14:50:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	prtf_putstr(char *str)
{
	size_t length;

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
	return (length);
}

// // char	*uitolchex(unsigned int n)
// // {
// //
// // }
// size_t	print_lchex(unsigned int n)
// {
// 	size_t	length;
// 	char	*str;
//
// 	str = uitolchex(n);
// 	length = ft_strlen(str);
// 	ft_putstr_fd(str, 1);
// 	free(str);
// 	return(length);
// }
