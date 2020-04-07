/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:33:51 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/09 21:40:17 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	add_first_token(t_token **token, char *content,
t_asm_content *content_asm)
{
	if (!(*token = (t_token *)ft_memalloc(sizeof(t_token))))
		error(content_asm);
	(*token)->content = ft_strdup(content);
	interpretation(*token, content_asm);
	(*token)->memory_size = 0;
	(*token)->next = NULL;
	(*token)->previous = NULL;
}

static void	add_token(t_token **token, char *content,
t_asm_content *content_asm)
{
	t_token	*copy;
	t_token	*new;

	copy = *token;
	if (*content == ' ' || *content == '\n' || *content == '\0')
		return ;
	if (!copy)
		add_first_token(token, content, content_asm);
	else
	{
		if (!(new = (t_token *)ft_memalloc(sizeof(t_token))))
			error(content_asm);
		new->content = ft_strdup(content);
		interpretation(new, content_asm);
		new->next = NULL;
		new->memory_size = 0;
		while (copy->next)
			copy = copy->next;
		copy->next = new;
		new->previous = copy;
	}
}

void		tokenizing(char **line, t_strings **row, t_asm_content **content)
{
	char	**buff;
	char	**copy_buff;
	t_token	*tokens;

	tokens = NULL;
	buff = NULL;
	if (skip_simple_comment_emptyline(line) == 1)
		return ;
	if ((buff = create_buff(line, content)) == NULL)
		return ;
	copy_buff = buff;
	while (*copy_buff)
	{
		if (**copy_buff == ALT_COMMENT_CHAR || **copy_buff == COMMENT_CHAR)
			break ;
		add_token(&tokens, *copy_buff++, *content);
	}
	add_string(&tokens, row, *content);
	clear_buff(buff);
	free(buff);
}
