/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:23:02 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/11 16:18:10 by rjeong           ###   ########.fr       */
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
	while (n > 9)
	{
		n /= 10;
		++digit;
	}
	return (digit);
}

long long	ft_cal_ltoa(char *dst, long long i, long long num)
{
	*(dst + i) = '0' + (num % 10);
	if (num < 10)
		return (i);
	else
		return (ft_cal_ltoa(dst, i + 1, num / 10));
}

char	*ft_long_to_ascii(long long n)
{
	char		*dst;
	long long	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		++size;
	}
	size += ft_cal_digit(n);
	dst = (char *) malloc (sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	if (ft_cal_ltoa(dst, 0, n) + 1 < size)
		*(dst + size - 1) = '-';
	*(dst + size) = '\0';
	return (ft_strrev(dst, size));
}
