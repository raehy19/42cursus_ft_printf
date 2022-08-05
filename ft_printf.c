/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:56:03 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/03 14:56:05 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose_functions(int i, va_list ap)
{
	int	(*functions[8])(va_list);

	functions[0] = ft_type_character;
	functions[1] = ft_type_string;
	functions[2] = ft_type_int;
	functions[3] = ft_type_int;
	functions[4] = ft_type_int;
	functions[5] = ft_type_int;
	functions[6] = ft_type_int;
	functions[7] = ft_type_int;
	return (functions[i](ap));
}

int	ft_check_type(const char c, va_list ap)
{
	const char	*options = "csdiuxXp";
	int			i;

	i = -1;
	while (++i < 9)
	{
		if (*(options + i) == '%')
		{
			write(1, "%", 1);
			return (0);
		}
		if (*(options + i) == c)
			return (ft_choose_functions(i, ap));
	}
	return (-1);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, input);
	i = 0;
	while (*(input + i) != '\0')
	{
		if (*(input + i) == '%')
		{
			++i;
			if (ft_check_type(*(input + i), ap))
				return (-1);
		}
		else
			write(1, input + i, 1);
		++i;
	}
	va_end(ap);
	return (i);
}
