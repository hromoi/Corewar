/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:20:40 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/20 20:03:59 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check(t_token *pointer)
{
	if (!ft_strcmp(pointer->type, INSTRACTION_NAME) &&
	(!ft_strcmp(pointer->content, LIVE_NAME)
	|| !ft_strcmp(pointer->content, FORK_NAME)
	|| !ft_strcmp(pointer->content, LFORK_NAME)
	|| !ft_strcmp(pointer->content, ZJMP_NAME)))
		return (0);
	return (1);
}

void	fill_write(t_token *pointer, t_strings *rows, t_asm_content **content)
{
	int flag;

	flag = 0;
	fill_write_code_instraction(pointer->content, content);
	if (check(pointer))
		fill_write_code_arg(pointer, content);
	fill_write_arg(pointer, rows, content, flag);
}

void	fill_file(t_strings *rows, t_asm_content **content)
{
	t_token		*pointer;
	t_strings	*rows_start;

	rows_start = rows;
	while (rows)
	{
		pointer = rows->string;
		while (pointer)
		{
			if (!ft_strcmp(pointer->type, INSTRACTION_NAME))
				fill_write(pointer, rows_start, content);
			pointer = pointer->next;
		}
		rows = rows->next;
	}
}
