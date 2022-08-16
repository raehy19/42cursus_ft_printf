/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:13:45 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/05 16:13:46 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"

int		ft_strlen(const char *s);
char	*ft_strrev(char *str, long long len);
char	*ft_long_to_ascii(long long n);
char	*ft_unsigned_long_to_ascii(unsigned long long n);
char	*ft_unsigned_hex_to_ascii(unsigned long long n, char flag);
int		ft_isdigit(int c);
int		ft_max(int a, int b);

#endif
