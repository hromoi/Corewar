/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:00:18 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:31:19 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_value(unsigned char *field, int position)
{
	unsigned char	result[REG_SIZE];
	int				i;

	if (position >= 0)
		position %= (MEM_SIZE);
	else
		position = (MEM_SIZE) + (position % (MEM_SIZE));
	i = 0;
	while (i < REG_SIZE)
	{
		result[i] = field[(position + REG_SIZE - i - 1) % (MEM_SIZE)];
		i++;
	}
	return (*((int *)result));
}

void		ldi(t_game *game, t_carriage *carriage)
{
	int	a;
	int	b;

	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	if (carriage->args_type[0] == T_REG)
		a = carriage->reg[carriage->args[0]];
	else
		a = carriage->args[0];
	if (carriage->args_type[1] == T_REG)
		b = carriage->reg[carriage->args[1]];
	else
		b = carriage->args[1];
	carriage->reg[carriage->args[2]] = get_value(game->field,
									carriage->position + (a + b) % (IDX_MOD));
}
