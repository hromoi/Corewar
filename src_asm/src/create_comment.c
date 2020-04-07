/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:14:55 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:34:17 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_comment_champ_strcat(char *comment, t_norminette *struct_norme)
{
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, struct_norme->comment_cmd_string);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, QUOTATION_MARK);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, ROUND_BRACKET_OPEN);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, struct_norme->alt_comment_char);
	ft_strcat(comment, struct_norme->comment_char);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, POINT);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, ROUND_BRACKET_CLOSE);
	ft_strcat(comment, QUESTION);
	ft_strcat(comment, DOLLAR);
}

void	strdel_comment_champ(t_norminette *struct_norme)
{
	ft_strdel(&struct_norme->comment_cmd_string);
	ft_strdel(&struct_norme->alt_comment_char);
	ft_strdel(&struct_norme->comment_char);
}

char	*create_comment_champ(t_asm_content *content)
{
	char			*comment;
	int				length;
	t_norminette	struct_norme;

	struct_norme.comment_cmd_string = str_screening(COMMENT_CMD_STRING,
	content);
	struct_norme.alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	struct_norme.comment_char = screen(COMMENT_CHAR, content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(struct_norme.comment_cmd_string) +
	ft_strlen(SPACE_OR_TAB) + ft_strlen(MULTIPLIER) +
	ft_strlen(QUOTATION_MARK) + ft_strlen(SQUARE_BRACKET_OPEN) +
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(QUOTATION_MARK) +
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(MULTIPLIER) +
	ft_strlen(QUOTATION_MARK) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_OPEN) +
	ft_strlen(SQUARE_BRACKET_OPEN) + ft_strlen(struct_norme.alt_comment_char) +
	ft_strlen(struct_norme.comment_char) + ft_strlen(SQUARE_BRACKET_CLOSE) +
	ft_strlen(POINT) +
	ft_strlen(MULTIPLIER) + ft_strlen(ROUND_BRACKET_CLOSE) +
	ft_strlen(QUESTION) + ft_strlen(DOLLAR);
	(!(comment = ft_strnew(length))) ? error(content) : 0;
	create_comment_champ_strcat(comment, &struct_norme);
	strdel_comment_champ(&struct_norme);
	return (comment);
}

void	create_comment_strcat(char *comment, t_norminette *struct_norme)
{
	ft_strcat(comment, CIRCUMFLEXUS);
	ft_strcat(comment, SPACE_OR_TAB);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, SQUARE_BRACKET_OPEN);
	ft_strcat(comment, struct_norme->alt_comment_char);
	ft_strcat(comment, struct_norme->comment_char);
	ft_strcat(comment, SQUARE_BRACKET_CLOSE);
	ft_strcat(comment, POINT);
	ft_strcat(comment, MULTIPLIER);
	ft_strcat(comment, DOLLAR);
}

char	*create_comment(t_asm_content *content)
{
	char			*comment;
	int				length;
	t_norminette	struct_norme;

	struct_norme.alt_comment_char = screen(ALT_COMMENT_CHAR, content);
	struct_norme.comment_char = screen(COMMENT_CHAR, content);
	length = ft_strlen(CIRCUMFLEXUS) + ft_strlen(SPACE_OR_TAB) +
	ft_strlen(MULTIPLIER) + ft_strlen(SQUARE_BRACKET_OPEN) +
	ft_strlen(struct_norme.alt_comment_char) +
	ft_strlen(struct_norme.comment_char) +
	ft_strlen(SQUARE_BRACKET_CLOSE) + ft_strlen(POINT) +
	ft_strlen(MULTIPLIER) + ft_strlen(DOLLAR);
	if (!(comment = ft_strnew(length)))
		error(content);
	create_comment_strcat(comment, &struct_norme);
	ft_strdel(&struct_norme.alt_comment_char);
	ft_strdel(&struct_norme.comment_char);
	return (comment);
}
