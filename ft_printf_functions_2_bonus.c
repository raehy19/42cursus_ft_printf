/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:02:50 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/05 15:02:52 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_type_hex_lower(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					size;

	if (!flag)
		return (0);
	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	if (!str)
		return (-1);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

int	ft_type_hex_upper(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					size;

	if (!flag)
		return (0);
	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'A');
	if (!str)
		return (-1);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

int	ft_type_pointer(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int *);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	len = ft_strlen(str);
	if (flag->precision > len)
		len = flag->precision;
	if (!str)
		return (-1);
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	if (write (1, "0x", 2) < 0)
		return (ft_free_n_return(str, -1));
	if (ft_print_space(1, flag->precision - (ft_strlen(str))) < 0)
		return (ft_free_n_return(str, -1));
	if (write(1, str, ft_strlen(str)) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	if (flag->min_width > len + 2)
		return (ft_free_n_return(str, flag->min_width));
	return (ft_free_n_return(str, len + 2));
}
