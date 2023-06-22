/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:13:22 by iusantos          #+#    #+#             */
/*   Updated: 2023/06/22 11:40:45 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
/* %s */
size_t	prtf_putstr(char *str);
/* %d and %i */
size_t	print_int(int nbr);
void	write_str(long n, char *str, size_t length);
/*  %u */
char	*ft_uitoa(unsigned int n);
size_t	print_uint(unsigned int nbr);
/*  %x and %X */
void	write_hex_str(unsigned long n, char *str, size_t length, char c);
char	*uitohex(unsigned long n, char c);
size_t	print_hex(unsigned long n, char c);
/*  %p */
void	write_pref_hex_str(unsigned long n, char *str, size_t length);
char	*ultoa(unsigned long n);
size_t	print_voidp(void *p);
/* utils */
size_t	count_digit_base(unsigned long n, unsigned int base);

#endif //FT_PRINTF_H
