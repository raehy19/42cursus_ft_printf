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
	functions[4] = ft_type_unsigned_int;
	functions[5] = ft_type_hex_lower;
	functions[6] = ft_type_hex_upper;
	functions[7] = ft_type_pointer;
	return (functions[i](ap));
}

int	ft_check_type(const char c, va_list ap)
{
	const char	*types = "csdiuxXp";
	int			i;

	if (c == '%')
		return (write(1, "%", 1));
	i = -1;
	while (++i < 8)
		if (*(types + i) == c)
			return (ft_choose_functions(i, ap));
	return (write(1, &c, 1));
}

int	ft_check_format(const char *input, int *i, int *print_size, va_list ap)
{
	int	write_size;

	if (*(input + (*i)) == '%')
	{
		write_size = ft_check_type(*(input + (++(*i))), ap);
		if (write_size < 0)
		{
			*(print_size) = -1;
			return (-1);
		}
		*(print_size) += write_size;
	}
	else
	{
		write_size = write(1, input + (*i), 1);
		if (write_size < 0)
		{
			*(print_size) = -1;
			return (-1);
		}
		*(print_size) += write_size;
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
		if (ft_check_format(input, &i, &print_size, ap) < 0)
			break ;
	va_end(ap);
	return (print_size);
}
