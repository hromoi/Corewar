/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern_length_fifth.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:44:39 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:45:04 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_pattern_length_fifth(t_norminette *struct_norme)
{
	int length;

	length = ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->separator) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(struct_norme->reg) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir) + ft_strlen(PIPELINE) +
	ft_strlen(struct_norme->dir_label) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(PIPELINE) + ft_strlen(AFF_NAME) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(PLUS) +
	ft_strlen(struct_norme->reg) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(QUESTION) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(struct_norme->comment_char) +
	ft_strlen(struct_norme->alt_comment_char) +
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(POINT) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(QUESTION) + ft_strlen(DOLLAR);
	return (length);
}

void	strcat_pattern_first(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, CIRCUMFLEXUS);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, INSTRACTION_FIRST);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_SECOND);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
}

void	strcat_pattern_second(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, struct_norme->dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, ST_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, struct_norme->reg);
}

void	strcat_pattern_third(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_THIRD);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, SPACE_OR_TAB);
}

void	strcat_pattern_fourth(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, INSTRACTION_FOURTH);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir_label);
}
