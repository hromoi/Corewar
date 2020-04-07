/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:13:55 by astanton          #+#    #+#             */
/*   Updated: 2020/03/09 13:22:50 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_usage_and_exit(char *msg, t_game *game)
{
	if (msg)
	{
		write(1, "\x1b[35m\n", 6);
		write(2, msg, ft_strlen(msg));
	}
	write(1, "\x1b[31m\nUsage: ./corewar [-dump nbr_cycles | -v] [[-n number] \
champion1.cor] ...\n\n  -v		   : visualization mode\n  \
-dump nbr_cycles : Dumps memory after nbr_cycles cycles\n  \
-n	number	   : Sets the number of the next player, where 0 < n < ", 235);
	ft_putnbr(MAX_PLAYERS + 1);
	write(1, "\x1b[0m\n\n", 6);
	free_resources(*game);
	exit(1);
}

void	ft_print_error_message(char *msg, char *file, t_game *game)
{
	write(2, "\n\x1b[35m", 6);
	write(2, msg, ft_strlen(msg));
	if (file)
		write(2, file, ft_strlen(file));
	write(2, "\n\x1b[0m", 5);
	free_resources(*game);
	exit(1);
}
