/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:23:13 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/07 18:23:15 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"
# include "libft/libft.h"

typedef struct s_flag
{
	int	type;
	int	min_width;
	int	precision;
	int	display_sign;
	int	align_left;
	int	fill_zero;
	int	display_zero_x;
}	t_flag;

int	ft_printf(const char *input, ...);

void	ft_check_type(t_flag *flag, char c);
void	ft_check_precision(t_flag *flag, const char *input, int *i);

#endif
