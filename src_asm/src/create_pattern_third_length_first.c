/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern_third_length_first.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:36:46 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:37:18 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_pattern_third_length_first(t_norminette *struct_norme)
{
	int				length;

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
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB);
	return (length);
}

int		create_pattern_third_length_second(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->reg) +
	ft_strlen(PIPELINE) + ft_strlen(ST_NAME) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) +
	ft_strlen(struct_norme->reg) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) +
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
	ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN);
	return (length);
}

int		create_pattern_third_length_third(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) +
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
	ft_strlen(INSTRACTION_FIFTH) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(SPACE_OR_TAB);
	return (length);
}

int		create_pattern_third_length_fourth(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(PLUS) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(PIPELINE) + ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) + ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme->separator) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) + ft_strlen(STI_NAME) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) + ft_strlen(struct_norme->reg) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB);
	return (length);
}

int		create_pattern_third_length_fifth(t_norminette *struct_norme)
{
	int				length;

	length = ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir_label) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->indir_label) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir) +
	ft_strlen(PIPELINE) + ft_strlen(struct_norme->dir_label) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(PIPELINE) +
	ft_strlen(AFF_NAME) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(PLUS) + ft_strlen(struct_norme->reg) +
	ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(struct_norme->comment_char) +
	ft_strlen(struct_norme->alt_comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE)
	+ ft_strlen(POINT) + ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	return (length);
}
