/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:46:05 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/12/10 23:47:41 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_intlen(int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n /= 10;
		n *= -1;
		ret += 2;
	}
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_op(char *re, int len, long nb)
{
	re[len--] = 0;
	if (nb == 0)
	{
		re[0] = '0';
		return (re);
	}
	if (nb < 0)
	{
		re[0] = '-';
	}
	while (nb != 0)
	{
		re[len--] = '0' + ft_abs(nb % 10);
		nb /= 10;
	}
	return (re);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*re;
	char	*tmp;

	len = ft_intlen(n);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	nb = n;
	re = ft_op(tmp, len, nb);
	return (re);
}
