/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:43:40 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 14:04:30 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		open_close_fd(char *file, int var, int close_fd, t_game *game)
{
	int	fd;

	if (var == 1)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			ft_print_usage_and_exit("Can't open file, check filename, please.",
									game);
		return (fd);
	}
	else if (close(close_fd))
		ft_print_error_message("Can't close file.", NULL, game);
	return (-1);
}

static t_player	*fill_player(char *file_name, int id, t_game *game)
{
	t_player	*player;
	int			fd;

	fd = open_close_fd(file_name, 1, 0, game);
	player = (t_player*)malloc(sizeof(t_player));
	if (!player)
		ft_print_error_message("Memory for player is not allocated.", NULL,
								game);
	player->name = NULL;
	player->comment = NULL;
	player->code = NULL;
	player->name = save_name(fd, game);
	player->size_of_code = save_size_of_code(fd);
	player->comment = save_comment(fd, game);
	player->code = save_exec_code(fd, player->size_of_code, game);
	player->player_id = id;
	player->last_live = 0;
	player->prev = NULL;
	player->next = NULL;
	open_close_fd(file_name, 2, fd, game);
	return (player);
}

static int		find_number(int check)
{
	int	i;

	i = 1;
	while (i <= MAX_PLAYERS)
	{
		if (!(check & (1 << i)))
			return (i);
		i++;
	}
	return (0);
}

static char		refill_champs_id(t_player *players)
{
	int			check;
	int			n;
	t_player	*tmp;

	check = 0;
	tmp = players;
	while (tmp)
	{
		if (tmp->player_id)
			check = check | (1 << tmp->player_id);
		tmp = tmp->next;
	}
	tmp = players;
	while (tmp)
	{
		if (!tmp->player_id)
		{
			n = find_number(check);
			tmp->player_id = n;
			check = check | (1 << n);
		}
		tmp = tmp->next;
	}
	return (check);
}

t_player		*init_players(int ac, char **av, t_game *game)
{
	t_player	*players;
	t_player	*tmp;
	int			i;
	int			champ_id;

	i = ac - 1;
	players = NULL;
	game->car_number = 0;
	while (i > 0 && ft_strcmp(av[i - 1], "-dump") && ft_strcmp(av[i], "-v"))
	{
		champ_id = (i > 2 && !ft_strcmp(av[i - 2], "-n")) ?
			ft_atoi(av[i - 1]) : 0;
		tmp = fill_player(av[i], champ_id, game);
		tmp->next = players;
		(players) ? players->prev = tmp : 0;
		players = tmp;
		(game->car_number)++;
		i -= (i > 2 && (!ft_strcmp(av[i - 2], "-n")
			|| !ft_strcmp(av[i - 2], "-dump"))) ? 3 : 1;
	}
	game->players_id = refill_champs_id(players);
	return (players);
}
