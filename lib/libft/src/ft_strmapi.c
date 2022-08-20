/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:43:52 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/11/17 00:49:18 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*re;
	unsigned int	len;
	unsigned int	i;

	if (s == 0 || f == 0)
		return (0);
	i = -1;
	len = ft_strlen(s);
	re = malloc(sizeof(char) * (len + 1));
	if (!re)
		return (0);
	while (++i < len)
		re[i] = f(i, s[i]);
	re[i] = 0;
	return (re);
}
