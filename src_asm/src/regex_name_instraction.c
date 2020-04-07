/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_name_instraction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:20:43 by yperra-f          #+#    #+#             */
/*   Updated: 2020/03/11 20:42:14 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	strcat_create_pattern_name_or_comment_champs(char
*pattern_name_or_comment, char *name_cmd_string,
char *comment_cmd_string)
{
	ft_strcat(pattern_name_or_comment, CIRCUMFLEXUS);
	ft_strcat(pattern_name_or_comment, SPACE_OR_TAB);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, ROUND_BRACKET_OPEN);
	ft_strcat(pattern_name_or_comment, name_cmd_string);
	ft_strcat(pattern_name_or_comment, PIPELINE);
	ft_strcat(pattern_name_or_comment, comment_cmd_string);
	ft_strcat(pattern_name_or_comment, ROUND_BRACKET_CLOSE);
	ft_strcat(pattern_name_or_comment, SPACE_OR_TAB);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, QUOTATION_MARK);
	ft_strcat(pattern_name_or_comment, POINT);
	ft_strcat(pattern_name_or_comment, MULTIPLIER);
	ft_strcat(pattern_name_or_comment, DOLLAR);
}

char	*create_pattern_name_or_comment_champs(t_asm_content *content)
{
	char	*pattern_name_or_comment;
	char	*name_cmd_string;
	char	*comment_cmd_string;

	name_cmd_string = str_screening(NAME_CMD_STRING, content);
	comment_cmd_string = str_screening(COMMENT_CMD_STRING, content);
	if (!(pattern_name_or_comment = ft_strnew(
	strlen_pattern_name_or_comment_champs(name_cmd_string,
	comment_cmd_string))))
		error(content);
	strcat_create_pattern_name_or_comment_champs(pattern_name_or_comment,
	name_cmd_string, comment_cmd_string);
	ft_strdel(&name_cmd_string);
	ft_strdel(&comment_cmd_string);
	return (pattern_name_or_comment);
}
