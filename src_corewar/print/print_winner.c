/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:18:53 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 05:23:24 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_winner(t_game *game)
{
	t_player	*tmp;

	tmp = game->players;
	while (tmp && (tmp->player_id != -(game->last_survivor)))
		tmp = tmp->next;
	write(1, "Contestant ", 11);
	ft_putnbr(tmp->player_id);
	write(1, ", \"", 3);
	write(1, tmp->name, ft_strlen(tmp->name));
	write(1, "\", has won !\n", 13);
}
