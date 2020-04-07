/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:34:44 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:31:26 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	live(t_game *game, t_carriage *carriage)
{
	t_player	*tmp;

	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	tmp = game->players;
	while (tmp && tmp->player_id != -carriage->args[0])
		tmp = tmp->next;
	if (tmp)
	{
		game->last_survivor = carriage->args[0];
		tmp->last_live = game->current_cycle;
	}
	carriage->last_live_cycle = game->current_cycle;
	game->number_of_live_instructions += 1;
}
