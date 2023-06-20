/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:10:55 by iusantos          #+#    #+#             */
/*   Updated: 2023/06/20 11:56:23 by iusantos         ###   ########.fr       */
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
