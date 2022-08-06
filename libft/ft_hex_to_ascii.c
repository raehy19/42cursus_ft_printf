/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:51:55 by rjeong            #+#    #+#             */
/*   Updated: 2022/08/05 15:52:15 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_cal_digit_hex(long long n)
{
	long long	digit;

	digit = 1;
	while (n > 15)
	{
		n /= 16;
		++digit;
	}
	return (digit);
}

long long	ft_cal_ltoa_hex_u(char *dst, long long i, long long num)
{
	if (num / 10 > 0)
		*(dst + i) = 'A' + (num % 10);
	else
		*(dst + i) = '0' + (num % 10);
	if (num < 16)
		return (i);
	else
		return (ft_cal_ltoa_hex_u(dst, i + 1, num / 16));
}

long long	ft_cal_ltoa_hex_l(char *dst, long long i, long long num)
{
	if (num / 10 > 0)
		*(dst + i) = 'a' + (num % 10);
	else
		*(dst + i) = '0' + (num % 10);
	if (num < 16)
		return (i);
	else
		return (ft_cal_ltoa_hex_l(dst, i + 1, num / 16));
}

char	*ft_hex_to_ascii(long long n, char flag)
{
	char		*dst;
	long long	size;

	size = 0;
	size += ft_cal_digit_hex(n);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	if (flag == 'l')
		ft_cal_ltoa_hex_l(dst, 0, n);
	else if (flag == 'u')
		ft_cal_ltoa_hex_u(dst, 0, n);
	else
		return (NULL);
	*(dst + size) = '\0';
	return (ft_strrev(dst, size));
}
