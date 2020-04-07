/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:45:27 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 19:28:29 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	line_is_space(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (1);
	else
		return (0);
}

int			skip_simple_comment_emptyline(char **line)
{
	if (**line == '#' || ft_strlen(*line) == 0 || line_is_space(*line) == 1)
	{
		ft_strdel(line);
		return (1);
	}
	return (0);
}

static int	add_name(char **buff, t_asm_content **content)
{
	if (buff[1])
		(*content)->name = ft_strdup(buff[1]);
	else if (!buff[1])
	{
		(*content)->name = (char *)ft_memalloc(sizeof(char));
		*(*content)->name = '\0';
	}
	if (!(*content)->name)
		error(*content);
	clear_buff(buff);
	return (1);
}

static int	add_comment(char **buff, t_asm_content **content)
{
	if (buff[1])
		(*content)->comment = ft_strdup(buff[1]);
	else if (!buff[1])
	{
		(*content)->comment = (char *)ft_memalloc(sizeof(char));
		*(*content)->comment = '\0';
	}
	clear_buff(buff);
	return (1);
}

int			check_name_or_comment(char **buff, t_asm_content **content)
{
	if (!buff || !*buff || ft_isspace(**buff))
		return (1);
	if (ft_strcmp(*buff, NAME_CMD_STRING) == 0)
		return (add_name(buff, content));
	else if (ft_strcmp(*buff, COMMENT_CMD_STRING) == 0)
		return (add_comment(buff, content));
	return (0);
}
