/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_regex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:22:25 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:39:04 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pattern_third_strcat_eigth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
}

void	pattern_third_strcat_ninth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, AFF_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->comment_char);
	ft_strcat(pattern_third, struct_norme->alt_comment_char);
	ft_strcat(pattern_third, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern_third, POINT);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, DOLLAR);
}

void	pattern_third_strdel(t_norminette *struct_norme)
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

char	*create_pattern_third(t_asm_content *content)
{
	t_norminette	struct_norme;
	char			*pattern_third;
	int				length;

	init_struct_norme_for_pattern_third(&struct_norme, content);
	length = create_pattern_third_length_first(&struct_norme) +
	create_pattern_third_length_second(&struct_norme) +
	create_pattern_third_length_third(&struct_norme) +
	create_pattern_third_length_fourth(&struct_norme) +
	create_pattern_third_length_fifth(&struct_norme);
	if (!(pattern_third = ft_strnew(length)))
		error(content);
	pattern_third_strcat_first(pattern_third, &struct_norme);
	pattern_third_strcat_second(pattern_third, &struct_norme);
	pattern_third_strcat_third(pattern_third, &struct_norme);
	pattern_third_strcat_fourth(pattern_third, &struct_norme);
	pattern_third_strcat_fifth(pattern_third, &struct_norme);
	pattern_third_strcat_sixth(pattern_third, &struct_norme);
	pattern_third_strcat_seventh(pattern_third, &struct_norme);
	pattern_third_strcat_eigth(pattern_third, &struct_norme);
	pattern_third_strcat_ninth(pattern_third, &struct_norme);
	pattern_third_strdel(&struct_norme);
	return (pattern_third);
}
