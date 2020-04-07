/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:07:09 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 01:56:20 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	check_args(int *args, int op_code)
{
	int	i;

	i = 0;
	if (!g_ops[op_code].args_byte)
		return (0);
	while (i < g_ops[op_code].num_of_args)
	{
		if (!(args[i] & (g_ops[op_code]).arg_types[i]))
			return (1);
		i++;
	}
	return (0);
}
