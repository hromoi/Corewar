/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:00:46 by astanton          #+#    #+#             */
/*   Updated: 2020/02/25 15:38:25 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				main(int ac, char **av)
{
	t_game		game;

	game = init_game();
	verification_of_incoming_data(ac, av, &game);
	game.dump = (game.dump_cycles < 0) ? 0 : 1;
	game.players = init_players(ac, av, &game);
	game.players = sort_players(game.players);
	load_exec_code_in_battle_field(game, game.players);
	game.carriages = carriage_init(game.players, &game);
	game.last_survivor = -game.players->player_id;
	start_game(&game);
	free_resources(game);
	return (0);
}
