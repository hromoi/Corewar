/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:01:44 by astanton          #+#    #+#             */
/*   Updated: 2020/02/07 04:54:07 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	load_data_on_field(t_game *game, int pos, t_carriage *car,
								char *value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->field[(pos + i) % (MEM_SIZE)] = value[3 - i];
		if (game->visualization)
			game->colors[(pos + i) % (MEM_SIZE)] = game->colors[car->position];
		i++;
	}
}

void		st(t_game *game, t_carriage *carriage)
{
	int		position;
	char	result[2];

	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	if (carriage->args_type[1] == T_REG)
		carriage->reg[carriage->args[1]] = carriage->reg[carriage->args[0]];
	else
	{
		result[0] = game->field[(carriage->position + 4) % MEM_SIZE];
		result[1] = game->field[(carriage->position + 3) % MEM_SIZE];
		carriage->args[1] = (int)(*(short int *)result);
		position = carriage->position + (carriage->args[1] % (IDX_MOD));
		position = (position >= 0) ? position % (MEM_SIZE) :
							(MEM_SIZE) + (position % (MEM_SIZE));
		load_data_on_field(game, position, carriage,
					(char *)&(carriage->reg[carriage->args[0]]));
	}
}
