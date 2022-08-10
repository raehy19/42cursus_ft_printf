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

int	ft_type_character(va_list ap, t_flag *flag)
{
	char	c;
	int		write_size;
	int		i;

	i = 0;
	while (++i < flag->min_width)
		if (write(1, " ", 1) < 0)
			return (-1);
	c = (char) va_arg(ap, int);
	write_size = write(1, &c, 1);
	if (write_size < 0)
		return (-1);
	return (i + write_size);
}

int	ft_type_string(va_list ap, t_flag *flag)
{
	char	*str;
	int		write_size;
	int		i;
	int		len;

	i = -1;
	str = (char *) va_arg(ap, char *);
	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	if (flag->precision < len)
		len = flag->precision;
	if (len < flag->min_width)
	{
		if (flag->align_left == 1)
		{
			write_size = write(1, str, len);
			while (len + (++i) < flag->min_width)
				if (write(1, " ", 1) < 0)
					return (-1);
		}
		else
		{
			while (len + (++i) < flag->min_width)
				if (write(1, " ", 1) < 0)
					return (-1);
			write_size = write(1, str, len);
		}
	}
	if (write_size < 0)
		return (-1);
	return (i + write_size);
}

int	ft_type_int(va_list ap, t_flag *flag)
{
	long long	n;
	char		*str;
	int			i;
	int			size;

	i = -1;
	n = (long long) va_arg(ap, int);
	str = ft_long_to_ascii(n);
	if (!str)
		return (-1);
	if (ft_strlen(str) < flag->min_width)
	{
		while (++i < flag->min_width)
		{
			if (write(1, " ", 1) < 0)
			{
				free(str);
				return (-1);
			}
		}
	}
	size = write(1, str, ft_strlen(str));
	if (size < 0)
		return (-1);
	return (i + size);
}

int	ft_type_unsigned_int(va_list ap, t_flag *flag)
{
	unsigned long long	n;
	char				*str;
	int					size;

	if (!flag)
		return (0);
	n = (unsigned long long) va_arg(ap, unsigned int);
	str = ft_unsigned_long_to_ascii(n);
	if (!str)
		return (-1);
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}
