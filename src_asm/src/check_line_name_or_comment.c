/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_name_or_comment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:33:50 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 18:34:58 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	name(char *line)
{
	size_t	name_len;
	char	*possible_name;

	name_len = ft_strlen(NAME_CMD_STRING);
	if (ft_strlen(line) <= name_len || (ft_isspace(line[name_len]) == 0
	&& line[name_len] != '"'))
		return (0);
	possible_name = (char*)ft_memalloc((name_len + 1) * sizeof(char));
	possible_name = ft_strncpy(possible_name, line, name_len);
	possible_name[name_len] = '\0';
	if (ft_strcmp(possible_name, NAME_CMD_STRING) == 0)
	{
		ft_strdel(&possible_name);
		return (1);
	}
	ft_strdel(&possible_name);
	return (0);
}

static int	comment(char *line)
{
	size_t	comment_len;
	char	*possible_comment;

	comment_len = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strlen(line) <= comment_len || (ft_isspace(line[comment_len]) == 0
	&& line[comment_len] != '"'))
		return (0);
	possible_comment = (char*)ft_memalloc((comment_len + 1) * sizeof(char));
	possible_comment = ft_strncpy(possible_comment, line, comment_len);
	possible_comment[comment_len] = '\0';
	if (ft_strcmp(possible_comment, COMMENT_CMD_STRING) == 0)
	{
		ft_strdel(&possible_comment);
		return (1);
	}
	ft_strdel(&possible_comment);
	return (0);
}

int			check_line_name_or_comment(char *line, t_asm_content **content)
{
	char *c_name;
	char *c_comm;

	c_name = ft_strdup(NAME_CMD_STRING);
	c_comm = ft_strdup(COMMENT_CMD_STRING);
	if (!*c_name || !*c_comm)
	{
		ft_strdel(&c_name);
		ft_strdel(&c_comm);
		error(*content);
	}
	ft_strdel(&c_name);
	ft_strdel(&c_comm);
	if (name(line) == 1 && !(*content)->name)
		return (1);
	else if (comment(line) == 1 && !(*content)->comment)
		return (1);
	else
		return (0);
}
