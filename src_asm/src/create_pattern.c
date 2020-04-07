/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:18:31 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:46:17 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	strdel_create_pattern(t_norminette *struct_norme)
{
	ft_strdel(&struct_norme->reg);
	ft_strdel(&struct_norme->dir);
	ft_strdel(&struct_norme->dir_label);
	ft_strdel(&struct_norme->indir);
	ft_strdel(&struct_norme->indir_label);
	ft_strdel(&struct_norme->label);
	ft_strdel(&struct_norme->separator);
	ft_strdel(&struct_norme->alt_comment_char);
	ft_strdel(&struct_norme->comment_char);
}

char	*create_pattern(t_asm_content *content)
{
	char			*pattern;
	int				length;
	t_norminette	struct_norme;

	init_create_pattern(&struct_norme, content);
	length = create_pattern_length_first(&struct_norme) +
	create_pattern_length_second(&struct_norme) +
	create_pattern_length_third(&struct_norme) +
	create_pattern_length_fourth(&struct_norme) +
	create_pattern_length_fifth(&struct_norme);
	if (!(pattern = ft_strnew(length)))
		error(content);
	strcat_pattern_first(pattern, &struct_norme);
	strcat_pattern_second(pattern, &struct_norme);
	strcat_pattern_third(pattern, &struct_norme);
	strcat_pattern_fourth(pattern, &struct_norme);
	strcat_pattern_sixth(pattern, &struct_norme);
	strcat_pattern_seventh(pattern, &struct_norme);
	strcat_pattern_eigth(pattern, &struct_norme);
	strcat_pattern_ninth(pattern, &struct_norme);
	strcat_pattern_ten(pattern, &struct_norme);
	strdel_create_pattern(&struct_norme);
	return (pattern);
}
