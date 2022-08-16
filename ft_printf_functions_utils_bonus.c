/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_utils_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:45:30 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/11 08:45:31 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_space(int is_zero, int count)
{
	char	space;
	int		i;

	space = ' ';
	if (is_zero == 1)
		space = '0';
	i = -1;
	while (++i < count)
		if (write(1, &space, 1) < 0)
			return (-1);
	if (count > 0)
		return (count);
	return (0);
}

int	ft_print_num_minus(char *str, int len, t_flag *flag)
{
	if (flag->precision < 0)
		if (write(1, "-", 1) < 0)
			return (-1);
	if (flag->align_left == 0)
		if (ft_print_space(flag->fill_zero, flag->min_width - len - 1) < 0)
			return (-1);
	if (flag->precision > -1)
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

	if (write(1, str, ft_strlen(str)) < 0)
		return (-1);
	if (flag->align_left == 1)
		if (ft_print_space(0, flag->min_width - len - flg) < 0)
			return (-1);
	return (0);
}
