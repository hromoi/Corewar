/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_write_code_instraction.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:39:31 by yperra-f          #+#    #+#             */
/*   Updated: 2020/02/20 19:42:12 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	fill_write_code_instraction(char *instraction, t_asm_content **content)
{
	char	c;
	char	*bytecode;

	bytecode = (*content)->bytecode;
	c = '\0';
	if (!ft_strcmp(instraction, LIVE_NAME))
		c |= LIVE;
	else if (!ft_strcmp(instraction, LD_NAME))
		c |= LD;
	else if (!ft_strcmp(instraction, ST_NAME))
		c |= ST;
	else if (!ft_strcmp(instraction, ADD_NAME))
		c |= ADD;
	else if (!ft_strcmp(instraction, SUB_NAME))
		c |= SUB;
	else if (!ft_strcmp(instraction, AND_NAME))
		c |= AND;
	else if (!ft_strcmp(instraction, OR_NAME))
		c |= OR;
	c = fill_write_code_instraction_help(instraction, c);
	bytecode += (*content)->header_size;
	*bytecode = c;
	(*content)->header_size += ONE_BYTE;
}

char	fill_write_code_instraction_help(char *instraction, char c)
{
	if (!ft_strcmp(instraction, XOR_NAME))
		c |= XOR;
	else if (!ft_strcmp(instraction, ZJMP_NAME))
		c |= ZJMP;
	else if (!ft_strcmp(instraction, LDI_NAME))
		c |= LDI;
	else if (!ft_strcmp(instraction, STI_NAME))
		c |= STI;
	else if (!ft_strcmp(instraction, FORK_NAME))
		c |= FORK;
	else if (!ft_strcmp(instraction, LLD_NAME))
		c |= LLD;
	else if (!ft_strcmp(instraction, LLDI_NAME))
		c |= LLDI;
	else if (!ft_strcmp(instraction, LFORK_NAME))
		c |= LFORK;
	else if (!ft_strcmp(instraction, ADD_NAME))
		c |= ADD;
	else if (!ft_strcmp(instraction, AFF_NAME))
		c |= AFF;
	return (c);
}
