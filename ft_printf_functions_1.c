/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:33:37 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/05 14:33:39 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_character(va_list ap)
{
	char	c;

	c = (char) va_arg(ap, int);
	write(1, &c, 1);
	return (0);
}

int	ft_type_string(va_list ap)
{
	char	*str;

	str = (char *) va_arg(ap, char *);
	if (!str)
		write(1, "(null)", 6);
	else
		write(1, str, ft_strlen(str));
	return (0);
}

int	ft_type_int(va_list ap)
{
	long long	n;
	char		*str;

	n = (long long) va_arg(ap, int);
	str = ft_long_to_ascii(n);
	if (!str)
		return (-1);
	write(1, str, ft_strlen(str));
	return (0);
}


