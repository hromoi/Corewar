/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_indir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:30:11 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:30:41 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*create_dir(t_asm_content *content)
{
	char	*dir;
	char	*direct_char;
	int		length;

	direct_char = screening(DIRECT_CHAR, content);
	length = ft_strlen(direct_char) + ft_strlen(MINUS) +
	ft_strlen(QUESTION) +
	ft_strlen(NUMBERS) + ft_strlen(PLUS);
	if (!(dir = ft_strnew(length)))
		error(content);
	ft_strcat(dir, direct_char);
	ft_strcat(dir, MINUS);
	ft_strcat(dir, QUESTION);
	ft_strcat(dir, NUMBERS);
	ft_strcat(dir, PLUS);
	ft_strdel(&direct_char);
	return (dir);
}

char	*create_indir_label_result(t_asm_content *content)
{
	char	*indir_label;
	char	*indir_label_result;

	indir_label = create_indir_label(content);
	indir_label_result = create_start_and_finish_str(indir_label, content);
	ft_strdel(&indir_label);
	return (indir_label_result);
}

char	*create_indir_label(t_asm_content *content)
{
	char	*indir_label;
	char	*label_char;
	int		length;

	label_char = screening(LABEL_CHAR, content);
	length = ft_strlen(label_char) + ft_strlen(SQUARE_BRACKET_OPEN) +
	ft_strlen(LABEL_CHARS) + ft_strlen(SQUARE_BRACKET_CLOSE) +
	ft_strlen(PLUS);
	if (!(indir_label = ft_strnew(length)))
		error(content);
	ft_memset(indir_label, '\0', length + 1);
	ft_strcat(indir_label, label_char);
	ft_strcat(indir_label, SQUARE_BRACKET_OPEN);
	ft_strcat(indir_label, LABEL_CHARS);
	ft_strcat(indir_label, SQUARE_BRACKET_CLOSE);
	ft_strcat(indir_label, PLUS);
	ft_strdel(&label_char);
	return (indir_label);
}

char	*create_indir_result(t_asm_content *content)
{
	char	*indir;
	char	*indir_result;

	indir = create_indir(content);
	indir_result = create_start_and_finish_str(indir, content);
	ft_strdel(&indir);
	return (indir_result);
}

char	*create_indir(t_asm_content *content)
{
	char	*indir;
	int		length;

	length = ft_strlen(MINUS) + ft_strlen(QUESTION) +
	ft_strlen(NUMBERS) + ft_strlen(PLUS);
	if (!(indir = ft_strnew(length)))
		error(content);
	ft_strcat(indir, MINUS);
	ft_strcat(indir, QUESTION);
	ft_strcat(indir, NUMBERS);
	ft_strcat(indir, PLUS);
	return (indir);
}
