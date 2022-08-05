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

char	*ft_strrev(char *str, long long len)
{
	long long	i;
	char		temp;

	i = 0;
	while (i < len - 1 - i)
	{
		temp = *(str + i);
		*(str + i) = *(str + len - 1 - i);
		*(str + len - 1 - i) = temp;
		++i;
	}
	return (str);
}

long long	ft_cal_digit(long long n)
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

long long	ft_cal_ltoa(char *dst, long long i, long long num)
{
	if (num / 10 > 0)
		*(dst + i) = 'a' + (num % 10);
	else
		*(dst + i) = '0' + (num % 10);
	if (num < 16)
		return (i);
	else
		return (ft_cal_ltoa(dst, i + 1, num / 16));
}

char	*ft_hex_to_ascii_lower(long long n)
{
	char		*dst;
	long long	size;

	size = 0;
	size += ft_cal_digit(n);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	ft_cal_ltoa(dst, 0, n);
	*(dst + size) = '\0';
	return (ft_strrev(dst, size));
}
