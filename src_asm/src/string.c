/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:13:59 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 19:27:54 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_string(t_token **tokens, t_strings **row, t_asm_content *content)
{
	t_strings	*copy;
	t_strings	*new;

	copy = *row;
	if (!copy)
	{
		if (!(*row = (t_strings *)ft_memalloc(sizeof(t_strings))))
			error(content);
		(*row)->string = *tokens;
		(*row)->next = NULL;
		content->tokens = row;
	}
	else
	{
		if (!(new = (t_strings *)ft_memalloc(sizeof(t_strings))))
			error(content);
		new->string = *tokens;
		new->next = NULL;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
}
