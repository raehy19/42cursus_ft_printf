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

int	ft_print_hex(char *str, int len, t_flag *flag)
{
	if (flag->precision > len)
		len = flag->precision;
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len) < 0)
			return (ft_free_n_return(str, -1));
	if (ft_print_space(1, flag->precision - (ft_strlen(str))) < 0)
		return (ft_free_n_return(str, -1));
	if (write(1, str, ft_strlen(str)) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len) < 0)
			return (ft_free_n_return(str, -1));
	return (ft_free_n_return(str, ft_max(flag->min_width, len)));
}

int	ft_print_pointer(char *str, int len, t_flag *flag, char *zero_x)
{
	if (flag->precision > len)
		len = flag->precision;
	if (flag->align_left == 0 && flag->fill_zero == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	if (write (1, zero_x, 2) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 0 && flag->fill_zero == 1)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	if (ft_print_space(1, flag->precision - (ft_strlen(str))) < 0)
		return (ft_free_n_return(str, -1));
	if (write(1, str, ft_strlen(str)) < 0)
		return (ft_free_n_return(str, -1));
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len - 2) < 0)
			return (ft_free_n_return(str, -1));
	return (ft_free_n_return(str, ft_max(flag->min_width, len + 2)));
}

int	ft_type_hex_lower(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	if (!str)
		return (-1);
	if (flag->precision == 0 && *str == '0')
	{
		free(str);
		if (flag->min_width > 0)
			return (ft_print_space(0, flag->min_width));
		else
			return (0);
	}
	if (flag->precision > -1)
		flag->fill_zero = 0;
	len = ft_strlen(str);
	if (flag->display_zero_x == 1 && *(str) != '0')
		return (ft_print_pointer(str, len, flag, "0x"));
	return (ft_print_hex(str, len, flag));
}

int	ft_type_hex_upper(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_hex_to_ascii(n, 'A');
	if (!str)
		return (-1);
	if (flag->precision == 0 && *str == '0')
	{
		free(str);
		if (flag->min_width > 0)
			return (ft_print_space(0, flag->min_width));
		else
			return (0);
	}
	if (flag->precision > -1)
		flag->fill_zero = 0;
	len = ft_strlen(str);
	if (flag->display_zero_x == 1 && *(str) != '0')
		return (ft_print_pointer(str, len, flag, "0X"));
	return (ft_print_hex(str, len, flag));
}

int	ft_type_pointer(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					len;

	n = (unsigned long long) va_arg(ap, unsigned int *);
	str = ft_unsigned_hex_to_ascii(n, 'a');
	if (!str)
		return (-1);
	len = ft_strlen(str);
	return (ft_print_pointer(str, len, flag, "0x"));
}
