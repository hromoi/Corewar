/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:37:38 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 18:34:10 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		clear_buff(char **buff)
{
	char	**copy;
	int		len;

	len = 0;
	copy = buff;
	if (!buff || !*buff)
		return ;
	while (*copy++)
		len++;
	while (len)
		ft_strdel(&buff[--len]);
}

static void	space_replacement(char **line, int size, char c)
{
	char	*copy;
	int		quotes;

	quotes = 0;
	copy = *line;
	while (*copy && --size != -1)
	{
		if (*copy == '"' && quotes == 1)
			quotes = 0;
		if (*copy == '"' && quotes == 0)
			quotes = 1;
		if (ft_isspace(*copy) && quotes == 0)
			*copy = c;
		copy++;
	}
}

char		**create_buff(char **line, t_asm_content **content)
{
	char	**buff;
	char	c;

	*line = ft_left_trim(line);
	c = (check_line_name_or_comment(*line, content) == 0) ?
	SEPARATOR_CHAR : '"';
	space_replacement(line, ft_strlen(*line), c);
	buff = ft_strsplit(*line, c);
	if (**line == '.')
	{
		if (check_name_or_comment(buff, content) == 1)
		{
			ft_strdel(line);
			clear_buff(buff);
			free(buff);
			return (NULL);
		}
	}
	ft_strdel(line);
	return (buff);
}
