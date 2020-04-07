/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_arg_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:11:30 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 02:01:26 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	*decode_arg_byte(unsigned char byte, int op_code)
{
	int	*args;
	int	i;
	int	move;

	if (!g_ops[op_code].args_byte)
		return (g_ops[op_code].arg_types);
	args = ft_malloc(sizeof(int) * 3);
	move = 6;
	i = 0;
	while (i < 3)
	{
		args[i] = (byte >> move) & 3;
		if (args[i] == REG_CODE)
			args[i] = T_REG;
		else if (args[i] == DIR_CODE)
			args[i] = T_DIR;
		else if (args[i] == IND_CODE)
			args[i] = T_IND;
		move -= 2;
		i++;
	}
	return (args);
}
