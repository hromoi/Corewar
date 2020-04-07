/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:02:34 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 06:32:15 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	zjmp(t_game *game, t_carriage *carriage)
{
	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid || !carriage->carry)
		return ;
	carriage->offset = carriage->args[0] % (IDX_MOD);
}
