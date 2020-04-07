/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_exec_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:25:54 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 14:11:00 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	find_size_of_champ_field(t_game *game)
{
	int			champs;
	t_player	*tmp;

	tmp = game->players;
	champs = 0;
	while (tmp)
	{
		champs++;
		tmp = tmp->next;
	}
	game->num_of_files = champs;
	return ((MEM_SIZE) / champs);
}

static void	check_size_of_field(t_game *game, int size)
{
	t_player	*tmp;

	tmp = game->players;
	while (tmp)
	{
		if (tmp->size_of_code > size)
			ft_print_usage_and_exit("Not enough space on the field for so \
many champions!", game);
		tmp = tmp->next;
	}
}

void		load_exec_code_in_battle_field(t_game game, t_player *players)
{
	t_player		*tmp;
	unsigned char	*field;
	int				one_champ_size;

	tmp = players;
	while (tmp->next)
		tmp = tmp->next;
	field = game.field;
	one_champ_size = find_size_of_champ_field(&game);
	check_size_of_field(&game, one_champ_size);
	while (tmp)
	{
		ft_memcpy(field, tmp->code, tmp->size_of_code);
		field += one_champ_size;
		tmp = tmp->prev;
	}
}
