/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:20:46 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/07 18:20:52 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_choose_functions(int i, va_list ap)
{
	int	(*functions[8])(va_list);

	functions[0] = ft_type_character;
	functions[1] = ft_type_string;
	functions[2] = ft_type_int;
	functions[3] = ft_type_int;
	functions[4] = ft_type_unsigned_int;
	functions[5] = ft_type_hex_lower;
	functions[6] = ft_type_hex_upper;
	functions[7] = ft_type_pointer;
	return (functions[i](ap));
}

int	ft_type_check(char c)
{
	const char	*types = "csdiuxXp";
	int			i;

	i = -1;
	while (++i < 8)
		if (*(types + i) == c)
			return (i);
	return (-1);
}

int	ft_option_check(char c)
{
	const char	*options = "-0. +#";
	int			i;

	i = -1;
	while (++i < 6)
		if (*(options + i) == c)
			return (i);
	return (-1);
}

int	ft_flag(const char *input, int *i, va_list ap, int *print_size)
{
	t_flag	flag;

	flag = (t_flag) {-1, 0, 0, 0, 0, 0, 0};
	if (*(input + (++(*i))) == '%')
		*(print_size) += write(1, "%", 1);
	else
	{
		while (*(input + (++(*i))) != '\0')
		{
			if (ft_type_check(*(input + (*i))) > -1)
				;
		}
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		print_size;
	int		i;

	va_start(ap, input);
	print_size = 0;
	i = -1;
	while (*(input + (++i)) != '\0')
	{
		if (*(input + i) == '%')
		{
			ft_flag(input, &i, ap, &print_size);
		}
		else
			print_size += write(1, input + i, 1);
	}
	va_end(ap);
	return (print_size);
}
