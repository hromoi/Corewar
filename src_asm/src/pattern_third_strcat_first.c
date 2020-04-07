/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_third_strcat_first.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:38:05 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:38:29 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pattern_third_strcat_first(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, CIRCUMFLEXUS);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, QUESTION);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, INSTRACTION_FIRST);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_SECOND);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
}

void	pattern_third_strcat_second(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, ST_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
}

void	pattern_third_strcat_third(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_THIRD);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
}

void	pattern_third_strcat_fourth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FOURTH);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->indir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
}

void	pattern_third_strcat_fifth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
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
}
