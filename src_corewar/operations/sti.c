/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:01:56 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:31:47 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	load_data_on_field(t_game *game, int pos, t_carriage *car,
								int reg)
{
	int		i;
	char	*value;

	value = (char *)&reg;
	if (pos >= 0)
		pos %= (MEM_SIZE);
	else
		pos = (MEM_SIZE) + (pos % (MEM_SIZE));
	i = 0;
	while (i < 4)
	{
		game->field[(pos + i) % (MEM_SIZE)] = value[3 - i];
		if (game->visualization)
			game->colors[(pos + i) % (MEM_SIZE)] = game->colors[car->position];
		i++;
	}
}

void		sti(t_game *game, t_carriage *carriage)
{
	int	a;
	int	b;

	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	if (carriage->args_type[1] == T_REG)
		a = carriage->reg[carriage->args[1]];
	else
		a = carriage->args[1];
	if (carriage->args_type[2] == T_REG)
		b = carriage->reg[carriage->args[2]];
	else
		b = carriage->args[2];
	load_data_on_field(game, carriage->position + (a + b) % (IDX_MOD), carriage,
			carriage->reg[carriage->args[0]]);
}
