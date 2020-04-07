/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:52:50 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 14:27:03 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <pthread.h>
#include <ncurses.h>

static char	*get_colors_field(t_game *game)
{
	char		*color_field;
	int			i;
	int			j;
	t_player	*tmp;
	t_carriage	*car;

	color_field = (char *)ft_malloc(sizeof(char) * MEM_SIZE);
	i = -1;
	tmp = game->players;
	car = game->carriages;
	while (++i < MEM_SIZE)
		color_field[i] = 0;
	while (tmp)
	{
		i = car->position;
		j = i + tmp->size_of_code;
		while (i < j)
			color_field[i++] = (tmp->player_id) % 4 + 1;
		tmp = tmp->next;
		car = car->next;
	}
	return (color_field);
}

static void	thread_func(t_keyboard *keyboard)
{
	char	c;

	keyboard->end = 0;
	while (1)
	{
		if (keyboard->end)
			pthread_exit(0);
		read(0, &c, 1);
		if (c == ' ')
			keyboard->pause = (keyboard->pause) ? 0 : 1;
		else if (c == 'q')
		{
			keyboard->quit = 1;
			keyboard->pause = 0;
			pthread_exit(0);
		}
		else if (c == '+')
			keyboard->speed -= (keyboard->speed >= 20000) ? 20000 : 0;
		else if (c == '-')
			keyboard->speed += (keyboard->speed < 1000000) ? 20000 : 0;
	}
}

static void	start_game_with_visual(t_game *game)
{
	pthread_t		*new_thread;
	t_keyboard		*keyboard;

	game->colors = get_colors_field(game);
	keyboard = (t_keyboard *)ft_malloc(sizeof(t_keyboard));
	keyboard->pause = 1;
	keyboard->quit = 0;
	keyboard->speed = 300000;
	new_thread = (pthread_t *)ft_malloc(sizeof(pthread_t));
	pthread_create(new_thread, NULL, (void *)&thread_func, keyboard);
	start_game_cycle(game, keyboard);
	free(keyboard);
	free(game->colors);
	keyboard->end = 1;
	pthread_join(*new_thread, NULL);
	free(new_thread);
}

static void	start_game_simple(t_game *game)
{
	int	cycle;

	cycle = (game->dump) ? game->dump_cycles : 1;
	while (cycle && game->carriages)
	{
		cycle -= game->dump;
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
	}
	(!game->carriages) ? print_winner(game) : dump_field(game->field);
}

void		start_game(t_game *game)
{
	if (game->visualization)
	{
		init_ncurses();
		start_game_with_visual(game);
		endwin();
	}
	else
	{
		introducing_players(game->players);
		start_game_simple(game);
	}
}
