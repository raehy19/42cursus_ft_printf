/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_1_bonus.c                      :+:      :+:    :+:   */
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
	return (write(1, &c, 1));
}

int	ft_type_string(va_list ap)
{
	char	*str;

	str = (char *) va_arg(ap, char *);
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}

int	ft_type_int(va_list ap)
{
	long long	n;
	char		*str;
	int			size;

	n = (long long) va_arg(ap, int);
	str = ft_long_to_ascii(n);
	if (!str)
		return (-1);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

int	ft_type_unsigned_int(va_list ap)
{
	unsigned long long	n;
	char				*str;
	int					size;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_long_to_ascii(n);
	if (!str)
		return (-1);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}
