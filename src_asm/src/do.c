/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:27:34 by yperra-f          #+#    #+#             */
/*   Updated: 2020/02/20 20:37:10 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*do_w2(t_asm_content *content, char *temp)
{
	if (content->flag_comment == 1 || strlen(temp) > COMMENT_LENGTH)
	{
		free(temp);
		return (NULL);
	}
	content->flag_comment = 1;
	return (temp);
}

char	*do_w1(t_asm_content *content, char *temp)
{
	if (content->flag_name == 1 || strlen(temp) > PROG_NAME_LENGTH)
	{
		free(temp);
		return (NULL);
	}
	content->flag_name = 1;
	return (temp);
}
