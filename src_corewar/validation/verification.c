/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:12:27 by astanton          #+#    #+#             */
/*   Updated: 2020/02/25 16:07:43 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_file(char *name_file, t_game *game)
{
	int	fd;

	if (ft_strcmp(ft_to_lower_case(ft_strrchr(name_file, '.')), ".cor"))
		ft_print_usage_and_exit("Wrong type of file.", game);
	fd = open(name_file, O_RDONLY);
	if (fd < 0)
		ft_print_usage_and_exit("Can't open file, check filename, please.",
								game);
	if (close(fd) != 0)
		ft_print_error_message("Can't close file : ", name_file, game);
}

static int	ft_isnumber(char *str, int var, int *num, t_game *game)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && i != 0) || (i == 0 && !ft_isdigit(str[i])
			&& str[i] != '-' && str[i] != '+'))
			return (0);
		i++;
	}
	if (var == 1)
	{
		n = ft_atoi(str);
		if (n < 1 || n > MAX_PLAYERS || (*num >> n & 1))
			ft_print_usage_and_exit("Wrong champion's id.", game);
		*num = *num | (1 << n);
	}
	return (1);
}

static void	check_arguments(int *types, char **av, int ac, t_game *game)
{
	int	i;

	i = (types[0] == -1) ? 1 : 0;
	if ((ac == 2 && types[0] == -1)
		|| (ac < 4 + i && types[i] != TYPE_FILE)
		|| (i > 0 && types[i] == TYPE_OPT_DUMP)
		|| (types[i] == TYPE_OPT_DUMP && types[i + 1] != TYPE_NUMBER))
		ft_print_usage_and_exit(NULL, game);
	if (types[i] == TYPE_OPT_DUMP)
		i++;
	while (++i < ac)
	{
		if (types[i - 1] == TYPE_FILE)
			check_file(av[i], game);
		else if (types[i - 1] == TYPE_OPT_N)
		{
			if (types[i] != TYPE_NUMBER
				|| !ft_isnumber(av[i + 1], 1, &game->num_of_id, game)
				|| types[i + 1] != TYPE_FILE)
				ft_print_usage_and_exit("Wrong option input.", game);
		}
	}
}

static int	choose_type(char *str, int *arg_types, int i, t_game *game)
{
	if (!(ft_strcmp(str, "-n")))
		return (TYPE_OPT_N);
	else if (!(ft_strcmp(str, "-dump")) && i < 4)
	{
		game->dump = i + 1;
		return (TYPE_OPT_DUMP);
	}
	else if (ft_isnumber(str, 0, 0, game) && (i > 1
	&& (arg_types[i - 2] == TYPE_OPT_DUMP || arg_types[i - 2] == TYPE_OPT_N)))
		return (TYPE_NUMBER);
	else
		return (TYPE_FILE);
}

void		verification_of_incoming_data(int ac, char **av, t_game *game)
{
	int	i;
	int	files;
	int	arg_types[ac - 1];

	i = 0;
	if (ac == 1)
		ft_print_usage_and_exit(NULL, game);
	if (!ft_strcmp(av[1], "-v"))
	{
		i++;
		arg_types[0] = -1;
		game->visualization = 1;
	}
	files = 0;
	while (++i < ac)
	{
		arg_types[i - 1] = choose_type(av[i], arg_types, i, game);
		if (arg_types[i - 1] == TYPE_FILE)
			files++;
	}
	check_arguments(arg_types, av, ac, game);
	game->dump_cycles = (game->dump) ? ft_atoi(av[game->dump]) : -1;
	game->num_of_files = files;
	check_binary_files(arg_types, av, ac, game);
}
