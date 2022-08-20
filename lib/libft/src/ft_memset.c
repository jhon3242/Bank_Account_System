/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:41:49 by choewonju         #+#    #+#             */
/*   Updated: 2021/12/08 15:52:03 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*start;
	unsigned char	value;
	size_t			i;

	start = (unsigned char *)dest;
	value = (unsigned char)c;
	i = -1;
	while (++i < n)
		start[i] = value;
	return (dest);
}
