/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:53:48 by astanton          #+#    #+#             */
/*   Updated: 2018/12/18 14:39:28 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *new;

	if (!lst || !f || !(*f))
		return (NULL);
	new = f(lst);
	fresh = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			while (fresh)
			{
				free(fresh);
				fresh = fresh->next;
			}
			return (NULL);
		}
		new = new->next;
	}
	return (fresh);
}
