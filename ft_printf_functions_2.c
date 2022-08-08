/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:02:50 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/05 15:02:52 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_hex_lower(va_list ap)
{
	unsigned long long	n;
	char				*str;
	int					size;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	if (!str)
		return (-1);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

int	ft_type_hex_upper(va_list ap)
{
	unsigned long long	n;
	char				*str;
	int					size;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'A');
	if (!str)
		return (-1);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

int	ft_type_pointer(va_list ap)
{
	unsigned long long	n;
	char				*str;
	int					size_1;
	int					size_2;

	n = (unsigned long long) va_arg(ap, unsigned int *);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	if (!str)
		return (-1);
	size_1 = write (1, "0x", 2);
	if (size_1 < 0)
		return (-1);
	size_2 = write(1, str, ft_strlen(str));
	free(str);
	if (size_2 < 0)
		return (-1);
	return (size_1 + size_2);
}
