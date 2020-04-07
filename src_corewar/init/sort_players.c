/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:46:00 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 14:02:01 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_player	*update_links(t_player **head)
{
	int			i;
	t_player	*new_head;
	t_player	*tmp;

	i = 0;
	while (i < MAX_PLAYERS && !(head[i]))
		i++;
	new_head = head[i];
	new_head->prev = NULL;
	new_head->next = NULL;
	tmp = new_head;
	while (++i < MAX_PLAYERS)
	{
		if (head[i])
		{
			tmp->next = head[i];
			tmp->next->prev = tmp;
			tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	return (new_head);
}

t_player		*sort_players(t_player *players)
{
	int			i;
	int			max;
	t_player	*tmp[MAX_PLAYERS];
	t_player	*cur;

	max = MAX_PLAYERS + 1;
	i = 0;
	while (--max > 0)
	{
		cur = players;
		while (cur && cur->player_id != max)
			cur = cur->next;
		tmp[i] = (cur) ? cur : NULL;
		i++;
	}
	return (update_links(tmp));
}
