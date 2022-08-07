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

typedef struct s_flag
{
	int	type;
	int	display_sign;
	int	align_left;
	int	min_width;
	int	precision;
	int	fill_zero;
	int	display_zero_x;
}	t_flag;

# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"
# include "libft/libft.h"

int	ft_printf(const char *input, ...);

int	ft_check_type(const char c, va_list ap);
int	ft_choose_functions(int i, va_list ap);
int	ft_type_character(va_list ap);
int	ft_type_string(va_list ap);
int	ft_type_int(va_list ap);
int	ft_type_unsigned_int(va_list ap);
int	ft_type_hex_lower(va_list ap);
int	ft_type_hex_upper(va_list ap);
int	ft_type_pointer(va_list ap);

#endif
