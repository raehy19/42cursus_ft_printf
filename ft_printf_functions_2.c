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
	long long	n;
	char		*str;

	n = (long long) va_arg(ap, int);
	str = ft_hex_to_ascii_lower(n);
	if (!str)
		return (-1);
	write(1, str, ft_strlen(str));
	return (0);
}
