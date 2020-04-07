/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:31:18 by astanton          #+#    #+#             */
/*   Updated: 2020/02/25 15:29:39 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_carriage	*create_carriage(t_game *game)
{
	t_carriage	*carriage;

	carriage = (t_carriage *)malloc(sizeof(t_carriage));
	if (!carriage)
		ft_print_error_message("Memory for carriage is not allocated.", NULL,
								game);
	carriage->next = NULL;
	return (carriage);
}

static int			find_step(t_player *players)
{
	int			champs;
	t_player	*tmp;

	tmp = players;
	champs = 0;
	while (tmp)
	{
		champs++;
		tmp = tmp->next;
	}
	return ((MEM_SIZE) / champs);
}

static void			fill_carriage(t_player *players, t_carriage *carriages,
									unsigned int position)
{
	int i;

	i = 0;
	carriages->id = players->player_id;
	carriages->carry = 0;
	carriages->operation_code = 0;
	carriages->last_live_cycle = 0;
	carriages->cycles_till_exec = 0;
	carriages->offset = 0;
	carriages->position = position;
	while (++i < 16)
		carriages->reg[i] = 0;
	carriages->reg[0] = -(players->player_id);
}

t_carriage			*carriage_init(t_player *players, t_game *game)
{
	t_carriage		*carriages;
	t_carriage		*tmp;
	unsigned int	position;
	unsigned int	step;

	position = 0;
	step = find_step(players);
	carriages = NULL;
	while (players->next)
		players = players->next;
	while (players)
	{
		tmp = create_carriage(game);
		fill_carriage(players, tmp, position);
		position += step;
		tmp->next = carriages;
		carriages = tmp;
		players = players->prev;
	}
	return (carriages);
}
