/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_write_code_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:40:52 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 19:41:43 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	fill_t_reg(int iter, char c)
{
	if (iter == 1)
		c |= 64;
	else if (iter == 2)
		c |= 16;
	else if (iter == 3)
		c |= 4;
	return (c);
}

char	fill_t_dir(int iter, char c)
{
	if (iter == 1)
		c |= 128;
	else if (iter == 2)
		c |= 32;
	else if (iter == 3)
		c |= 8;
	return (c);
}

char	fill_t_ind(int iter, char c)
{
	if (iter == 1)
		c |= 192;
	else if (iter == 2)
		c |= 48;
	else if (iter == 3)
		c |= 12;
	return (c);
}

void	fill_write_code_arg(t_token *pointer, t_asm_content **content)
{
	int		iter;
	char	c;

	c = 0;
	iter = 1;
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, DIRECT_NAME) ||
		!ft_strcmp(pointer->type, DIRECT_LABEL_NAME))
			c = fill_t_dir(iter, c);
		else if (!ft_strcmp(pointer->type, INDIRECT_NAME) ||
		!ft_strcmp(pointer->type, INDIRECT_LABEL_NAME))
			c = fill_t_ind(iter, c);
		else if (!ft_strcmp(pointer->type, REGISTER_NAME))
			c = fill_t_reg(iter, c);
		if (ft_strcmp(pointer->type, LABEL_NAME) &&
		ft_strcmp(pointer->type, INSTRACTION_NAME))
			iter++;
		pointer = pointer->next;
	}
	ft_memcpy((*content)->bytecode + (*content)->header_size, &c, ONE_BYTE);
	(*content)->header_size += ONE_BYTE;
}
