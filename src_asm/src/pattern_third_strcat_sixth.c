/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_third_strcat_sixth.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:38:43 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:39:09 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pattern_third_strcat_sixth(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, INSTRACTION_FIFTH);
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
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
}

void	pattern_third_strcat_seventh(char *pattern_third,
t_norminette *struct_norme)
{
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, struct_norme->dir_label);
	ft_strcat(pattern_third, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, PIPELINE);
	ft_strcat(pattern_third, STI_NAME);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, PLUS);
	ft_strcat(pattern_third, struct_norme->reg);
	ft_strcat(pattern_third, SPACE_OR_TAB);
	ft_strcat(pattern_third, MULTIPLIER);
	ft_strcat(pattern_third, struct_norme->separator);
}
