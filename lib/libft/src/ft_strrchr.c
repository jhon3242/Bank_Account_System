/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:40:01 by choewonju         #+#    #+#             */
/*   Updated: 2021/12/10 19:05:59 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	char	*back;
	int		i;

	i = ft_strlen(s);
	back = (char *)s;
	find = (char)c;
	while (i >= 0)
	{
		if (back[i] == find)
			return (back + i);
		i--;
	}
	return (0);
}
