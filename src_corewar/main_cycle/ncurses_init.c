/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 02:41:15 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 14:22:38 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "vm.h"

void		print_pause(t_keyboard *key)
{
	mvprintw(3, 215, "**PAUSE**");
	refresh();
	while (key->pause)
		;
	mvprintw(3, 215, "         ");
	refresh();
}

static int	print_players_condition(t_player *players, int i)
{
	while (players->next)
		players = players->next;
	while (players)
	{
		mvprintw(i, 210, "%-10d", players->last_live);
		i += 4;
		players = players->prev;
	}
	i -= 2;
	return (i);
}

void		print_game_conditions(t_game *game)
{
	t_player	*tmp;
	int			i;

	mvprintw(6, 208, "%-10d", game->current_cycle);
	mvprintw(8, 208, "%-10d", game->car_number);
	i = print_players_condition(game->players, 12);
	mvprintw(i, 222, "%-10d", game->number_of_live_instructions);
	mvprintw(i + 2, 210, "%5d", game->cycles_to_die);
	if (!game->carriages)
	{
		tmp = game->players;
		while (tmp->player_id != -game->last_survivor)
			tmp = tmp->next;
		attron(COLOR_PAIR(8));
		mvprintw(i + 12, 196, "Player -%d win! Congratulations, %s!",
						tmp->player_id, tmp->name);
		attroff(COLOR_PAIR(8));
	}
	refresh();
}

void		init_ncurses(void)
{
	initscr();
	start_color();
	curs_set(0);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	init_pair(8, COLOR_GREEN, COLOR_RED);
}
