/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:19:06 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/12/08 14:47:06 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*re;
	t_list	*cur;

	re = 0;
	if (!lst || !f)
		return (0);
	re = ft_lstnew(f(lst->content));
	if (re == 0)
		return (0);
	cur = re;
	while (lst->next)
	{
		lst = lst->next;
		cur->next = ft_lstnew(f(lst->content));
		if (cur->next == 0)
		{
			ft_lstclear(&re, del);
			return (0);
		}
		cur = cur->next;
	}
	return (re);
}
