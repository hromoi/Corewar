/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chmp_exec_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:08:16 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/20 19:45:32 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

u_int8_t			get_num_from_1byte(t_asm_content **content, int *i)
{
	unsigned char	rbyte;

	if (read((*content)->fd_src, &rbyte, 1) < 0)
		error(*content);
	(*i)++;
	return ((u_int8_t)rbyte);
}

int					get_num_from_nbyte(t_asm_content **content, int *i,
														u_int8_t t_dir_size)
{
	int				tmp;
	int				rez;
	int				j;
	unsigned char	rbyte;

	j = -1;
	tmp = 0;
	rez = 0;
	while (++j < t_dir_size)
	{
		if (read((*content)->fd_src, &rbyte, 1) <= 0)
			error(*content);
		(*i)++;
		if ((tmp = rbyte) > 0)
			tmp <<= 8 * (t_dir_size - j - 1);
		rez += tmp;
	}
	return (t_dir_size == 2 ? (short int)rez : rez);
}

void				get_args_types(t_asm_content **content, int *i,
														u_int8_t cur_op)
{
	int				j;
	unsigned char	rbyte;

	if (read((*content)->fd_src, &rbyte, 1) < 0)
		error(*content);
	(*i)++;
	j = ARGS_TYPES_COUNT;
	while (j-- > 0)
	{
		rbyte >>= 2;
		g_tab[cur_op].args_types[j] = 3 & rbyte;
	}
}

void				write_curr_op(t_asm_content **content, int *i,
														u_int8_t cur_op)
{
	int				j;
	char			*num;

	j = 0;
	ft_strcpy((*content)->buf + (*content)->b_pos, g_tab[cur_op].op_name);
	(*content)->b_pos += g_tab[cur_op].oname_size;
	(*content)->buf[(*content)->b_pos++] = ' ';
	while (g_tab[cur_op].args_types[j])
	{
		num = 0;
		if (g_tab[cur_op].args_types[j] == REG_CODE)
			write_reg(content, cur_op, i, j);
		else if (g_tab[cur_op].args_types[j] == DIR_CODE)
			write_dir(content, cur_op, i, j);
		else if (g_tab[cur_op].args_types[j] == IND_CODE)
			write_ind(content, cur_op, i, j);
		j++;
	}
	(*content)->buf[(*content)->b_pos++] = '\n';
}

void				parse_chmp_exec_code(t_asm_content **content)
{
	int				i;
	u_int8_t		cur_op;

	i = 0;
	while (i < (int)(*content)->exec_code_size)
	{
		if ((cur_op = get_num_from_1byte(content, &i)) > OP_TAB_SIZE - 1)
			error(*content);
		if (g_tab[cur_op].args_types_code)
			get_args_types(content, &i, cur_op);
		write_curr_op(content, &i, cur_op);
	}
}
