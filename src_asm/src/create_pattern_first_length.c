/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern_first_length.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:35:07 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:35:32 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_pattern_first_length(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->label) +
	ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(FIRST_CASE) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(POINT) +
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	return (length);
}

void	create_pattern_first_strcat(t_norminette *struct_norme,
									char *first_case)
{
	ft_strcat(first_case, CIRCUMFLEXUS);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, struct_norme->label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, QUESTION);
	ft_strcat(first_case, SPACE_OR_TAB);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, FIRST_CASE);
	ft_strcat(first_case, ROUND_BRACKET_OPEN);
	ft_strcat(first_case, struct_norme->dir);
	ft_strcat(first_case, PIPELINE);
	ft_strcat(first_case, struct_norme->dir_label);
	ft_strcat(first_case, ROUND_BRACKET_CLOSE);
	ft_strcat(first_case, POINT);
	ft_strcat(first_case, MULTIPLIER);
	ft_strcat(first_case, DOLLAR);
}

char	*create_pattern_first(t_asm_content *content)
{
	t_norminette	struct_norme;
	char			*first_case;

	struct_norme.label = create_label_first_stage(content);
	struct_norme.dir = create_dir(content);
	struct_norme.dir_label = create_dir_label(content);
	if (!(first_case = ft_strnew(create_pattern_first_length(&struct_norme))))
		error(content);
	create_pattern_first_strcat(&struct_norme, first_case);
	ft_strdel(&struct_norme.label);
	ft_strdel(&struct_norme.dir);
	ft_strdel(&struct_norme.dir_label);
	return (first_case);
}

char	*create_pattern_second(t_asm_content *content)
{
	char	*second_case;
	char	*label;
	int		length;

	label = create_label_first_stage(content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(label) +
	ft_strlen(POINT) +
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(second_case = ft_strnew(length)))
		error(content);
	ft_strcat(second_case, CIRCUMFLEXUS);
	ft_strcat(second_case, SPACE_OR_TAB);
	ft_strcat(second_case, MULTIPLIER);
	ft_strcat(second_case, label);
	ft_strcat(second_case, POINT);
	ft_strcat(second_case, MULTIPLIER);
	ft_strcat(second_case, DOLLAR);
	ft_strdel(&label);
	return (second_case);
}

void	init_struct_norme_for_pattern_third(t_norminette *struct_norme,
											t_asm_content *content)
{
	struct_norme->reg = create_reg(content);
	struct_norme->dir = create_dir(content);
	struct_norme->dir_label = create_dir_label(content);
	struct_norme->indir = create_indir(content);
	struct_norme->indir_label = create_indir_label(content);
	struct_norme->label = create_label_first_stage(content);
	struct_norme->separator = screen(SEPARATOR_CHAR, content);
	struct_norme->alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	struct_norme->comment_char = screen(COMMENT_CHAR, content);
}
