/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:44:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/28 17:35:01 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_pointer(unsigned long long n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += put_pointer(n / 16);
		ret += put_pointer(n % 16);
	}
	else
		ret += write(1, &"0123456789abcdef"[n], 1);
	return (ret);
}

int	print_pointer(unsigned long long n)
{
	int	ret;

	ret = 0;
	if (n == 0)
	{
		ret += write(1, "0x0", 3);
		return (ret);
	}
	ret += write(1, "0x", 2);
	ret += put_pointer(n);
	return (ret);
}
