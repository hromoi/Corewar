/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_comt_cs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:44:59 by timuryakubo       #+#    #+#             */
/*   Updated: 2020/02/18 19:27:33 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		file_is_binary(int fd, t_asm_content **content)
{
	unsigned char	rbyte;
	int				tmp;
	int				rez;
	int				i;

	i = -1;
	tmp = 0;
	rez = 0;
	while (++i < MAGIC_NUMBER_SIZE)
	{
		if (read(fd, &rbyte, 1) <= 0)
			error(*content);
		if ((tmp = rbyte) > 0)
			tmp <<= 8 * (MAGIC_NUMBER_SIZE - i - 1);
		rez += tmp;
	}
	return (rez == COREWAR_EXEC_MAGIC ? 1 : 0);
}

int		parse_name(char *buff, int *b_pos, int fd, t_asm_content **content)
{
	unsigned char	rbyte;
	int				i;

	ft_memcpy(buff, NAME_CMD_STRING, NAME_CMD_LEN);
	*b_pos = NAME_CMD_LEN;
	buff[(*b_pos)++] = ' ';
	buff[(*b_pos)++] = '"';
	i = *b_pos;
	while (i < NAME_CMD_LEN + 2 + PROG_NAME_LENGTH)
	{
		if (read(fd, &rbyte, 1) <= 0)
			error(*content);
		if (rbyte)
			buff[(*b_pos)++] = rbyte;
		i++;
	}
	buff[(*b_pos)++] = '"';
	buff[(*b_pos)++] = '\n';
	return (1);
}

int		parse_comment(char *buff, int *b_pos, int fd, t_asm_content **content)
{
	unsigned char	rbyte;
	int				i;
	int				start_pos;

	ft_memcpy(buff + *b_pos, COMMENT_CMD_STRING, COMMENT_CMD_LEN);
	*b_pos += COMMENT_CMD_LEN;
	buff[(*b_pos)++] = ' ';
	buff[(*b_pos)++] = '"';
	i = *b_pos;
	start_pos = *b_pos;
	while (i < start_pos + COMMENT_LENGTH)
	{
		if (read(fd, &rbyte, 1) <= 0)
			error(*content);
		if (rbyte)
			buff[(*b_pos)++] = rbyte;
		i++;
	}
	buff[(*b_pos)++] = '"';
	buff[(*b_pos)++] = '\n';
	buff[(*b_pos)++] = '\n';
	return (1);
}

void	skip_null_bytes(t_asm_content **content)
{
	unsigned char	rbyte;
	int				i;

	i = -1;
	while (++i < NULL_SIZE)
	{
		if (read((*content)->fd_src, &rbyte, 1) <= 0 || rbyte)
			error(*content);
	}
}

void	parse_chmp_exec_code_size(t_asm_content **content)
{
	unsigned char	rbyte;
	int				tmp;
	int				rez;
	int				i;

	i = -1;
	tmp = 0;
	rez = 0;
	while (++i < CHMP_CODE_VAR_SIZE)
	{
		if (read((*content)->fd_src, &rbyte, 1) <= 0)
			error(*content);
		if ((tmp = rbyte) > 0)
			tmp <<= 8 * (CHMP_CODE_VAR_SIZE - i - 1);
		rez += tmp;
	}
	(*content)->exec_code_size = rez;
}
