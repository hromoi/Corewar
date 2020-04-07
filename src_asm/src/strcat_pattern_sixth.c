/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat_pattern_sixth.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:45:54 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 21:05:18 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	strcat_pattern_sixth(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
}

void	strcat_pattern_seventh(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, INSTRACTION_FIFTH);
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
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
}

void	strcat_pattern_eigth(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, STI_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->reg);
}

void	strcat_pattern_ninth(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir_label);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->indir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, struct_norme->separator);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, struct_norme->dir_label);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, PIPELINE);
	ft_strcat(pattern, AFF_NAME);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, PLUS);
}

void	strcat_pattern_ten(char *pattern, t_norminette *struct_norme)
{
	ft_strcat(pattern, struct_norme->reg);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, SPACE_OR_TAB);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_OPEN);
	ft_strcat(pattern, SQUARE_BRACKET_OPEN);
	ft_strcat(pattern, struct_norme->comment_char);
	ft_strcat(pattern, struct_norme->alt_comment_char);
	ft_strcat(pattern, SQUARE_BRACKET_CLOSE);
	ft_strcat(pattern, POINT);
	ft_strcat(pattern, MULTIPLIER);
	ft_strcat(pattern, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern, QUESTION);
	ft_strcat(pattern, DOLLAR);
}
