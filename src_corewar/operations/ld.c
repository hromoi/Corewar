/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:29:06 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:31:13 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ld(t_game *game, t_carriage *carriage)
{
	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	carriage->reg[carriage->args[1]] = carriage->args[0];
	if (carriage->reg[carriage->args[1]])
		carriage->carry = 0;
	else
		carriage->carry = 1;
}
