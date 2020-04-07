/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create_pattern.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:32:29 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:33:04 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_create_pattern(t_norminette *struct_norme, t_asm_content *content)
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

int		create_pattern_length_first(t_norminette *struct_norme)
{
	int length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(QUESTION) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(INSTRACTION_FIRST) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) +
	ft_strlen(INSTRACTION_SECOND) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->indir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg);
	return (length);
}

int		create_pattern_length_second(t_norminette *struct_norme)
{
	int length;

	length = ft_strlen(PIPELINE) + ft_strlen(ST_NAME) + ft_strlen(SPACE_OR_TAB)
	+ ft_strlen(PLUS) + ft_strlen(struct_norme->reg) + ft_strlen(SPACE_OR_TAB)
	+ ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->reg) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) +
	ft_strlen(INSTRACTION_THIRD) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(PLUS) + ft_strlen(struct_norme->reg) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg) +
	ft_strlen(PIPELINE) + ft_strlen(INSTRACTION_FOURTH) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE);
	return (length);
}

int		create_pattern_length_third(t_norminette *struct_norme)
{
	int	length;

	length = ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->dir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->reg) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(INSTRACTION_FIFTH) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->reg) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->indir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE);
	return (length);
}

int		create_pattern_length_fourth(t_norminette *struct_norme)
{
	int length;

	length = ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg) +
	ft_strlen(PIPELINE) + ft_strlen(STI_NAME) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(PLUS) + ft_strlen(struct_norme->reg) + ft_strlen(SPACE_OR_TAB)
	+ ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->reg) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir_label) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE);
	return (length);
}
