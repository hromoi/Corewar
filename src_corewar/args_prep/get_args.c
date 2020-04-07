/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:37:44 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 02:52:50 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_dir_arg(int pos, unsigned char *field, int dir_size)
{
	unsigned char	result[dir_size];
	int				i;

	i = 0;
	while (i < dir_size)
	{
		result[i] = field[(pos + dir_size - i - 1) % (MEM_SIZE)];
		i++;
	}
	if (dir_size == 2)
		return ((int)(*(short int *)result));
	else
		return ((int)(*(int *)result));
}

static int	get_ind_arg(int pos, int car_pos, unsigned char *field, int op_code)
{
	int				offset;
	unsigned char	result[2];

	result[0] = field[(pos + 1) % (MEM_SIZE)];
	result[1] = field[pos];
	offset = (int)(*((short int *)result));
	if (g_ops[op_code].idx_mod)
		offset %= (IDX_MOD);
	pos = car_pos + offset;
	if (pos >= 0)
		pos = pos % (MEM_SIZE);
	else
		pos = (MEM_SIZE) + pos % (MEM_SIZE);
	return (get_dir_arg(pos, field, DIR_SIZE));
}

static int	get_value(int *args_type, t_game *game, t_carriage *carriage, int i)
{
	int	pos;

	pos = carriage->cur_position;
	if (args_type[i] == T_DIR)
	{
		carriage->args[i] = get_dir_arg(pos, game->field,
									g_ops[carriage->operation_code].dir_size);
		pos = g_ops[carriage->operation_code].dir_size;
	}
	else if (args_type[i] == T_IND)
	{
		carriage->args[i] = get_ind_arg(pos, carriage->position, game->field,
									carriage->operation_code);
		pos = IND_SIZE;
	}
	return (pos);
}

void		get_args(int *args_type, t_game *game, t_carriage *carriage)
{
	int i;
	int	pos;

	i = 0;
	pos = (carriage->position) + 1 + g_ops[carriage->operation_code].args_byte;
	while (i < g_ops[carriage->operation_code].num_of_args)
	{
		carriage->cur_position = pos;
		if (args_type[i] == T_REG)
		{
			carriage->args[i] = (int)((game->field)[pos % (MEM_SIZE)]) - 1;
			if (carriage->args[i] < 0 || carriage->args[i] > 15)
			{
				carriage->is_args_valid = 0;
				return ;
			}
			pos++;
		}
		else
			pos += get_value(args_type, game, carriage, i);
		i++;
	}
	while (i < 3)
		carriage->args[i++] = 0;
}
