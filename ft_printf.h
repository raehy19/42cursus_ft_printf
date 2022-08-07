/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:14:02 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/05 18:14:03 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

#endif
