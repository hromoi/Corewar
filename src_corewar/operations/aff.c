/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:59:08 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 14:33:45 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <ncurses.h>

void	aff(t_game *game, t_carriage *carriage)
{
	char	c;

	get_and_check_args(game, carriage);
	if (!carriage->is_args_valid)
		return ;
	c = carriage->reg[carriage->args[0]] % 256;
	if (game->visualization)
	{
		(game->aff)++;
		mvprintw(68, 0, "AFF : ");
		mvprintw(68 + (game->aff / 250), 6 + (game->aff % 250), "%c", c);
		refresh();
	}
	else
	{
		write(1, "Aff: ", 5);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
