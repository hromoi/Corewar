/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:01:00 by astanton          #+#    #+#             */
/*   Updated: 2020/01/28 20:52:28 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lld(t_game *game, t_carriage *carriage)
{
	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	carriage->reg[carriage->args[1]] = carriage->args[0];
	if (carriage->args[0])
		carriage->carry = 0;
	else
		carriage->carry = 1;
}
