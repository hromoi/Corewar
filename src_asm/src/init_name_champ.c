/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_name_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:41:43 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:42:25 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_name_champ(t_norminette *struct_norme, t_asm_content *content)
{
	struct_norme->name_cmd_string = str_screening(NAME_CMD_STRING, content);
	struct_norme->alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	struct_norme->comment_char = screen(COMMENT_CHAR, content);
}

int		strlen_name_champ(t_norminette *struct_norme)
{
	int length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) +
	ft_strlen(struct_norme->name_cmd_string) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(QUOTATION_MARK) + ft_strlen(SQUARE_BRACKET_OPEN) +
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(QUOTATION_MARK) +
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(MULTIPLIER) +
	ft_strlen(QUOTATION_MARK) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(struct_norme->alt_comment_char) +
	ft_strlen(struct_norme->comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) +
	ft_strlen(POINT) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(QUESTION) + ft_strlen(DOLLAR);
	return (length);
}

void	strcat_name_champ(char *name, t_norminette *struct_norme)
{
	ft_strcat(name, CIRCUMFLEXUS);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, struct_norme->name_cmd_string);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SQUARE_BRACKET_OPEN);
	ft_strcat(name, CIRCUMFLEXUS);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SQUARE_BRACKET_CLOSE);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, QUOTATION_MARK);
	ft_strcat(name, SPACE_OR_TAB);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, ROUND_BRACKET_OPEN);
	ft_strcat(name, SQUARE_BRACKET_OPEN);
	ft_strcat(name, struct_norme->alt_comment_char);
	ft_strcat(name, struct_norme->comment_char);
	ft_strcat(name, SQUARE_BRACKET_CLOSE);
	ft_strcat(name, POINT);
	ft_strcat(name, MULTIPLIER);
	ft_strcat(name, ROUND_BRACKET_CLOSE);
	ft_strcat(name, QUESTION);
	ft_strcat(name, DOLLAR);
}

char	*create_name_champ(t_asm_content *content)
{
	char			*name;
	t_norminette	struct_norme;

	init_name_champ(&struct_norme, content);
	if (!(name = ft_strnew(strlen_name_champ(&struct_norme))))
		error(content);
	strcat_name_champ(name, &struct_norme);
	ft_strdel(&struct_norme.alt_comment_char);
	ft_strdel(&struct_norme.comment_char);
	ft_strdel(&struct_norme.name_cmd_string);
	return (name);
}

int		strlen_pattern_name_or_comment_champs(char *name_cmd_string,
char *comment_cmd_string)
{
	int		length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) +
	ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(name_cmd_string) +
	ft_strlen(PIPELINE) +
	ft_strlen(comment_cmd_string) +
	ft_strlen(ROUND_BRACKET_CLOSE) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) +
	ft_strlen(QUOTATION_MARK) + ft_strlen(POINT) +
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	return (length);
}
