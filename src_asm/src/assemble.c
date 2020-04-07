/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:06:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/09 22:00:40 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	assemble(t_asm_content **content)
{
	t_strings		*rows;

	rows = NULL;
	create_regex(*content);
	while (get_next_line((*content)->fd_src, &(*content)->line) > 0)
	{
		if (!((*content)->line = check_valid((*content), (*content)->fd_src)))
			error(*content);
		tokenizing(&(*content)->line, &rows, content);
	}
	if (!(*content)->flag_pattern || !check_all_label(rows, content))
		error(*content);
	if (!((*content)->fd_dst = open((*content)->new_filename, \
	O_TRUNC | O_CREAT | O_RDWR, 0644)))
		error(*content);
	(*content)->exec_code_size = (*content)->memory_code_size;
	(*content)->asm_size = (*content)->exec_code_size + (*content)->header_size;
	(*content)->bytecode =
	(char *)ft_memalloc((*content)->asm_size * sizeof(char));
	ft_bzero((*content)->bytecode, (*content)->asm_size);
	in_bytecode(content);
	fill_file(rows, content);
	write((*content)->fd_dst, (*content)->bytecode, (*content)->asm_size);
	print_output_str(content);
	clean_memory(content);
}
