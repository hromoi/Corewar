/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_write_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:42:32 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 20:04:19 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		search_instraction_two(t_token *pointer)
{
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, INSTRACTION_NAME))
		{
			return (pointer->memory_size - (check(pointer) ?
			TWO_BYTE : ONE_BYTE));
		}
		pointer = pointer->previous;
	}
	return (0);
}

int		search_instraction(char *content, t_strings *rows)
{
	t_token *pointer;

	pointer = rows->string;
	while (rows)
	{
		pointer = rows->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, LABEL_NAME) &&
			!ft_strcmp(pointer->content, content))
			{
				ft_strdel(&content);
				return (pointer->memory_size);
			}
			pointer = pointer->next;
		}
		rows = rows->next;
	}
	return (0);
}

void	write_args(int length, int num, t_asm_content **content)
{
	char	temp[length];
	int		iter;
	int		i;

	iter = 0;
	i = length;
	ft_bzero(temp, 4);
	while (i--)
	{
		temp[i] = (char)(num >> iter);
		iter += 8;
	}
	ft_memcpy((*content)->bytecode +
	(*content)->header_size, temp, length);
	(*content)->header_size += length;
}

int		check_t_dir_size(t_token *pointer)
{
	if (!ft_strcmp(pointer->content, ZJMP_NAME)
	|| !ft_strcmp(pointer->content, LDI_NAME)
	|| !ft_strcmp(pointer->content, STI_NAME)
	|| !ft_strcmp(pointer->content, FORK_NAME)
	|| !ft_strcmp(pointer->content, LLDI_NAME)
	|| !ft_strcmp(pointer->content, LFORK_NAME))
		return (0);
	return (1);
}

void	fill_write_arg(t_token *pointer, t_strings *rows,
t_asm_content **content, int flag)
{
	while (pointer)
	{
		if (!ft_strcmp(pointer->type, INSTRACTION_NAME) && \
		check_t_dir_size(pointer))
			flag = 1;
		else if (!ft_strcmp(pointer->type, REGISTER_NAME))
			write_args(ONE_BYTE, ft_atoiwcm(ft_strsub(pointer->content, 1, \
			strlen(pointer->content))), content);
		else if (!ft_strcmp(pointer->type, DIRECT_NAME))
			write_args(flag ? FOUR_BYTE : TWO_BYTE, ft_atoiwcm(ft_strsub(\
			pointer->content, 1, strlen(pointer->content))), content);
		else if (!ft_strcmp(pointer->type, DIRECT_LABEL_NAME))
			write_args(flag ? FOUR_BYTE : TWO_BYTE, search_instraction(\
			ft_strjoinwcm(ft_strsub(pointer->content, 2, strlen(\
			pointer->content)), ":"), rows) - search_instraction_two(\
			pointer), content);
		else if (!ft_strcmp(pointer->type, INDIRECT_LABEL_NAME))
			write_args(TWO_BYTE, (search_instraction(ft_strjoinwcm(\
			ft_strsub(pointer->content, 1, strlen(pointer->content)), \
			":"), rows) - search_instraction_two(pointer)), content);
		else if (!ft_strcmp(pointer->type, INDIRECT_NAME))
			write_args(TWO_BYTE, atoi(pointer->content), content);
		pointer = pointer->next;
	}
}
