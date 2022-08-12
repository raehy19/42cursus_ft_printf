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
