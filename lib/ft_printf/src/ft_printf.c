/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:14:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/29 17:07:12 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(const char fmt, va_list *ap)
{
	int	ret;

	ret = 0;
	if (fmt == 'c')
		ret += print_char(va_arg(*ap, int));
	else if (fmt == 's')
		ret += print_str(va_arg(*ap, char *));
	else if (fmt == 'p')
		ret += print_pointer(va_arg(*ap, unsigned long long));
	else if (fmt == 'd' || fmt == 'i')
		ret += print_nub(va_arg(*ap, int));
	else if (fmt == 'u')
		ret += ft_unsigned_int(va_arg(*ap, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		ret += print_hex(va_arg(*ap, unsigned int), fmt);
	else
		ret += print_persent();
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	ap;

	ret = 0;
	i = -1;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ret += print_format(str[i + 1], &ap);
			i++;
		}
		else
			ret += write(1, str + i, 1);
	}
	va_end(ap);
	return (ret);
}
