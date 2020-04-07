/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:59:58 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:31:05 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_carriage	*copy_carriage(t_carriage *carriage)
{
	t_carriage	*new;
	int			i;

	new = (t_carriage *)ft_malloc(sizeof(t_carriage));
	new->carry = carriage->carry;
	new->last_live_cycle = carriage->last_live_cycle;
	new->cycles_till_exec = carriage->cycles_till_exec;
	new->is_args_valid = carriage->is_args_valid;
	new->offset = 0;
	new->operation_code = carriage->operation_code;
	i = carriage->position + (carriage->args[0] % (IDX_MOD));
	if (i >= 0)
		new->position = i % (MEM_SIZE);
	else
		new->position = (MEM_SIZE) + (i % (MEM_SIZE));
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = carriage->reg[i];
		i++;
	}
	return (new);
}

void				ft_fork(t_game *game, t_carriage *carriage)
{
	t_carriage	*new;

	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	new = copy_carriage(carriage);
	new->id = game->carriages->id + 1;
	new->next = game->carriages;
	game->carriages = new;
	(game->car_number)++;
}
