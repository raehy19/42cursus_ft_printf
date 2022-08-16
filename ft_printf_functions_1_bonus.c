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

#include "ft_printf_bonus.h"

int	ft_type_percent(t_flag *flag)
{
	int		write_size;

	write_size = 0;
	if (flag->align_left == 0)
		write_size = ft_print_space(flag->fill_zero, flag->min_width - 1);
	if (write(1, "%", 1) < 0)
		return (-1);
	if (flag->align_left == 1)
		write_size = ft_print_space(0, flag->min_width - 1);
	if (write_size < 0)
		return (-1);
	return (write_size + 1);
}

int	ft_type_character(va_list ap, t_flag *flag)
{
	char	c;
	int		write_size;

	c = (char) va_arg(ap, int);
	write_size = 0;
	if (flag->align_left == 0)
		write_size = ft_print_space(0, flag->min_width - 1);
	if (write(1, &c, 1) < 0)
		return (-1);
	if (flag->align_left == 1)
		write_size = ft_print_space(0, flag->min_width - 1);
	if (write_size < 0)
		return (-1);
	return (write_size + 1);
}

int	ft_type_string(va_list ap, t_flag *flag)
{
	const char	*null_str = "(null)";
	char		*str;
	int			len;

	str = (char *) va_arg(ap, char *);
	if (!str)
		str = (char *) null_str;
	len = ft_strlen(str);
	if (flag->precision > -1 && flag->precision < len)
		len = flag->precision;
	if (flag->align_left == 0)
		if (ft_print_space(0, flag->min_width - len) < 0)
			return (-1);
	if (write(1, str, len) < 0)
		return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len) < 0)
			return (-1);
	if (flag->min_width > len)
		return (flag->min_width);
	return (len);
}

int	ft_type_int(va_list ap, t_flag *flag)
{
	long long	n;
	char		*str;
	int			len;

	n = (long long) va_arg(ap, int);
	str = ft_long_to_ascii(n);
	if (!str)
		return (-1);
	if (flag->precision > -1)
		flag->fill_zero = 0;
	len = ft_strlen(str);
	if (flag->precision > len)
		len = flag->precision;
	if (*(str) == '-')
		if (ft_print_num_minus(str, len, flag))
			return (-1);
	if (*(str) != '-')
		if (ft_print_num_plus(str, len, flag))
			return (-1);
	if (*str == '0' && flag->min_width == 0 && flag->precision == 0)
		--len;
//	printf("\n\npre : %d / strlen : %d / space len : %d / min width : %d / len : %d\n\n", flag->precision, ft_strlen(str), flag->min_width - len, flag->min_width, len);
	free(str);
	if (flag->min_width > len)
		return (flag->min_width);
	return (len);
}


int	ft_print_num_minus(char *str, int len, t_flag *flag)
{
	if (flag->precision < 0)
		--len;
	if (flag->fill_zero == 1)
		if (write(1, "-", 1) < 0)
			return (-1);
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len) < 0)
			return (-1);
	if (flag->fill_zero == 0)
		if (write(1, "-", 1) < 0)
			return (-1);
	if (ft_print_space(1, flag->precision - (ft_strlen(str) - 1)) < 0)
		return (-1);
	if (write(1, str + 1, ft_strlen(str) - 1) < 0)
		return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len - 1) < 0)
			return (-1);
	return (0);
}

int	ft_print_num_plus(char *str, int len, t_flag *flag)
{
	char	sign;
	int		flg;

	flg = 1;
	if (flag->display_sign == 1)
		sign = '+';
	else if (flag->display_sign == 2)
		sign = ' ';
	else
		flg = 0;
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - flg) < 0)
			return (-1);
	if (ft_print_space(1, flag->precision - (ft_strlen(str))) < 0)
		return (-1);
	if (flg == 1)
		if (write(1, &sign, 1) < 0)
			return (-1);
	if (*str != '0' || flag->precision != 0)
		if (write(1, str, ft_strlen(str)) < 0)
			return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len - flg) < 0)
			return (-1);
	return (0);
}
