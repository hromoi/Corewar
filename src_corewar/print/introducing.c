/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introducing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:52:08 by astanton          #+#    #+#             */
/*   Updated: 2020/01/31 18:03:38 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	introducing_players(t_player *players)
{
	write(1, "Introducing contestants...\n", 27);
	while (players->next)
		players = players->next;
	while (players)
	{
		write(1, "* Player ", 9);
		ft_putnbr(players->player_id);
		write(1, ", weighing ", 11);
		ft_putnbr(players->size_of_code);
		write(1, " bytes, \"", 9);
		write(1, players->name, ft_strlen(players->name));
		write(1, "\" (\"", 4);
		write(1, players->comment, ft_strlen(players->comment));
		write(1, "\") !\n", 5);
		players = players->prev;
	}
}
