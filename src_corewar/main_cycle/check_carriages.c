/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carriages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:52:40 by astanton          #+#    #+#             */
/*   Updated: 2020/02/07 05:50:47 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	delete_carriage(t_game *game, t_carriage *current)
{
	t_carriage	*prev;
	t_carriage	*tmp;
	char		c;

	tmp = game->carriages;
	prev = NULL;
	while (tmp && tmp != current)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (prev)
		prev->next = tmp->next;
	else
		game->carriages = tmp->next;
	free(tmp);
	game->car_number--;
	c = 7;
	if (game->visualization)
		write(1, &c, 1);
}

void		check_carriages(t_game *game)
{
	t_carriage	*cur;
	t_carriage	*next;

	cur = game->carriages;
	while (cur)
	{
		next = cur->next;
		if (game->current_cycle - cur->last_live_cycle >= game->cycles_to_die)
			delete_carriage(game, cur);
		cur = next;
	}
}
