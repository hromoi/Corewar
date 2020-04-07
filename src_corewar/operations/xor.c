/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:02:22 by astanton          #+#    #+#             */
/*   Updated: 2020/02/21 23:14:18 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_xor(t_game *game, t_carriage *carriage)
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
	carriage->reg[carriage->args[2]] = a ^ b;
	if (carriage->reg[carriage->args[2]])
		carriage->carry = 0;
	else
		carriage->carry = 1;
}
