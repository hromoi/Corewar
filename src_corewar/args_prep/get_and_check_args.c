/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:58:53 by astanton          #+#    #+#             */
/*   Updated: 2020/02/05 05:11:08 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	copy_args_type(int *args_type, t_carriage *carriage)
{
	carriage->args_type[0] = args_type[0];
	carriage->args_type[1] = args_type[1];
	carriage->args_type[2] = args_type[2];
}

void		get_and_check_args(t_game *game, t_carriage *carriage)
{
	int *args_type;

	carriage->is_args_valid = 1;
	args_type = decode_arg_byte(game->field[(carriage->position + 1)
								% (MEM_SIZE)], carriage->operation_code);
	carriage->offset = get_offset(args_type, carriage->operation_code);
	if (check_args(args_type, carriage->operation_code))
	{
		carriage->is_args_valid = 0;
		free(args_type);
		return ;
	}
	get_args(args_type, game, carriage);
	copy_args_type(args_type, carriage);
	if (g_ops[carriage->operation_code].args_byte)
		free(args_type);
}
