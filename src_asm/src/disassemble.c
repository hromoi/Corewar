/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:55:04 by yperra-f          #+#    #+#             */
/*   Updated: 2020/02/29 18:55:09 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	disassemble(t_asm_content **content)
{
	if (!((*content)->buf = (char *)ft_memalloc((BUFF_SIZE_FOR_DIS) * \
	sizeof(char))))
		error(*content);
	if (file_is_binary((*content)->fd_src, content))
	{
		parse_name((*content)->buf, &((*content)->b_pos), (*content)->fd_src,
																	content);
		skip_null_bytes(content);
		parse_chmp_exec_code_size(content);
		parse_comment((*content)->buf, &((*content)->b_pos),
												(*content)->fd_src, content);
		skip_null_bytes(content);
		parse_chmp_exec_code(content);
		(*content)->buf[(*content)->b_pos] = 0;
		if (!((*content)->fd_dst = open((*content)->new_filename, \
		O_TRUNC | O_CREAT | O_RDWR, 0644)))
			error(*content);
		write((*content)->fd_dst, (*content)->buf, (*content)->b_pos);
		print_output_str(content);
	}
	else
		error(*content);
	clean_memory(content);
}
