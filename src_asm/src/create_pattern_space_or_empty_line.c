/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern_space_or_empty_line.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:34:00 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:34:23 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*create_pattern_space_or_empty_line(t_asm_content *content)
{
	char	*space_or_empty_line;
	int		length;

	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(space_or_empty_line = ft_strnew(length)))
		error(content);
	ft_strcat(space_or_empty_line, CIRCUMFLEXUS);
	ft_strcat(space_or_empty_line, SPACE_OR_TAB);
	ft_strcat(space_or_empty_line, MULTIPLIER);
	ft_strcat(space_or_empty_line, DOLLAR);
	return (space_or_empty_line);
}
