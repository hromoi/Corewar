/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_with_visual.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 23:57:16 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 14:43:33 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <ncurses.h>

static void	print_field(t_game *game, t_keyboard *keyboard)
{
	int			i;
	t_carriage	*tmp;

	print_game_conditions(game);
	i = 0;
	while (i < MEM_SIZE)
	{
		attron(COLOR_PAIR(game->colors[i]));
		mvprintw(i / 64 + 2, (i % 64) * 3 + 2, "%0.2hhx", game->field[i]);
		attroff(COLOR_PAIR(game->colors[i]));
		i++;
	}
	tmp = game->carriages;
	while (tmp)
	{
		i = tmp->position;
		attron(COLOR_PAIR(5));
		mvprintw(i / 64 + 2, (i % 64) * 3 + 2, "%0.2hhx", game->field[i]);
		attroff(COLOR_PAIR(5));
		tmp = tmp->next;
	}
	refresh();
	usleep(keyboard->speed);
}

static void	print_box(void)
{
	int	i;
	int	j;
	int	fin;

	i = 0;
	fin = MEM_SIZE / 64 + 4;
	while (i < fin)
	{
		attron(COLOR_PAIR(6));
		if (i == 0 || i == fin - 1)
		{
			j = -1;
			while (++j < 245)
				mvprintw(i, j, "%c", 'X');
		}
		else
		{
			mvprintw(i, 0, "%c", 'X');
			mvprintw(i, 194, "%c", 'X');
			mvprintw(i, 244, "%c", 'X');
		}
		i++;
	}
	attroff(COLOR_PAIR(6));
}

static int	print_players(t_player *players, int i)
{
	t_player	*tmp;

	tmp = players;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		attron(COLOR_PAIR(7));
		mvprintw(i, 196, "Player -%d : ", tmp->player_id);
		attron(COLOR_PAIR(tmp->player_id % 4 + 1));
		mvprintw(i, 209, "%s", tmp->name);
		attroff(COLOR_PAIR(tmp->player_id % 4 + 1));
		attron(COLOR_PAIR(7));
		mvprintw(i + 2, 198, "Last live : ");
		i += 4;
		tmp = tmp->prev;
	}
	return (i);
}

static void	print_window(t_game *game, t_keyboard *key)
{
	t_player	*tmp;
	int			i;

	print_box();
	attron(COLOR_PAIR(7));
	mvprintw(6, 196, "Cycle     : ");
	mvprintw(8, 196, "Processes : ");
	tmp = game->players;
	i = print_players(game->players, 10);
	mvprintw(i, 196, "Lives in current period : ");
	mvprintw(i + 2, 196, "CYCLE_TO_DIE : %-5d", CYCLE_TO_DIE);
	mvprintw(i + 4, 196, "CYCLE_DELTA  : %-5d", CYCLE_DELTA);
	mvprintw(i + 6, 196, "NBR_LIVE     : %-5d", NBR_LIVE);
	mvprintw(i + 8, 196, "MAX_CHECKS   : %-5d", MAX_CHECKS);
	attroff(COLOR_PAIR(7));
	print_field(game, key);
}

void		start_game_cycle(t_game *game, t_keyboard *keyboard)
{
	print_window(game, keyboard);
	while (game->carriages)
	{
		if (keyboard->quit)
			break ;
		(game->current_cycle)++;
		exec_all_carriages(game);
		if (game->current_cycle - game->last_check_cycle >= game->cycles_to_die
			|| game->cycles_to_die <= 0)
		{
			game->last_check_cycle = game->current_cycle;
			check_carriages(game);
			(game->number_of_checks)++;
			if (game->number_of_live_instructions >= NBR_LIVE
				|| game->number_of_checks == MAX_CHECKS)
			{
				game->cycles_to_die -= CYCLE_DELTA;
				game->number_of_checks = 0;
			}
			game->number_of_live_instructions = 0;
		}
		print_field(game, keyboard);
		if (keyboard->pause)
			print_pause(keyboard);
	}
}
