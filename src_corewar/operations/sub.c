/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:02:09 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:31:54 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sub(t_game *game, t_carriage *carriage)
{
	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	carriage->reg[carriage->args[2]] = carriage->reg[carriage->args[0]]
			- carriage->reg[carriage->args[1]];
	if (carriage->reg[carriage->args[2]])
		carriage->carry = 0;
	else
		carriage->carry = 1;
}
