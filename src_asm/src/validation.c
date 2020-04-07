/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:46:06 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 18:51:43 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*help_check_name_or_comment_champs(t_asm_content *content, int fd)
{
	char *temp;

	temp = ft_strnew(0);
	temp = ft_strjoinwcm(temp, content->line);
	ft_strdel(&content->line);
	if (parse(temp, content->regex_array[PATTERN_NAME_CHAMPS]))
		return (do_w1(content, temp));
	else if (parse(temp, content->regex_array[PATTERN_COMMENT_CHAMPS]))
		return (do_w2(content, temp));
	temp = ft_strjoinwcm(temp, "\n");
	while (get_next_line(fd, &content->line) > 0)
	{
		temp = ft_strjoinwcm(temp, content->line);
		ft_strdel(&content->line);
		if (parse(temp, content->regex_array[PATTERN_NAME_CHAMPS]))
			return (do_w1(content, temp));
		else if (parse(temp, content->regex_array[PATTERN_COMMENT_CHAMPS]))
			return (do_w2(content, temp));
		temp = ft_strjoinwcm(temp, "\n");
	}
	free(temp);
	return (NULL);
}

char	*help_validation(t_asm_content *content)
{
	if (parse(content->line,
	content->regex_array[PATTERN_HELP_VALIDATION_FIRST_CASE]))
		content->line = rebase_str_first_case(content->line);
	if (parse(content->line,
	content->regex_array[PATTERN_HELP_VALIDATION_SECOND_CASE]))
		content->line = rebase_str_second_case(content->line);
	if (parse(content->line,
	content->regex_array[PATTERN_HELP_VALIDATION_THIRD_CASE]))
		content->line = rebase_str_third_case(content->line);
	return (content->line);
}

char	*check_valid(t_asm_content *content, int fd)
{
	if (parse(content->line, content->regex_array[PATTERN_SPACE_OR_EMPTY_LINE]))
		return (content->line);
	else if (parse(content->line, \
	content->regex_array[PATTERN_NAME_OR_COMMENT_CHAMPS]))
		return (help_check_name_or_comment_champs(content, fd));
	else if (parse(content->line, content->regex_array[PATTERN_COMMENT]))
		return (content->line);
	else if (content->flag_name && content->flag_comment &&
	parse(content->line, content->regex_array[PATTERN]))
	{
		content->flag_pattern = 1;
		return (help_validation(content));
	}
	free(content->line);
	return (NULL);
}

char	*search_label(t_strings *rows, char *content,
t_asm_content *struct_content)
{
	t_token		*pointer;
	t_strings	*struct_pointer;

	struct_pointer = rows;
	while (struct_pointer)
	{
		pointer = struct_pointer->string;
		while (pointer)
		{
			if (label_validation(pointer, content, struct_content))
				return (content);
			pointer = pointer->next;
		}
		struct_pointer = struct_pointer->next;
	}
	return (NULL);
}

char	*check_all_label(t_strings *rows, t_asm_content **struct_content)
{
	t_token		*pointer;
	t_strings	*struct_pointer;
	int			flag;

	flag = 0;
	struct_pointer = rows;
	while (struct_pointer)
	{
		pointer = struct_pointer->string;
		while (pointer)
		{
			if ((!ft_strcmp(pointer->type, DIRECT_LABEL_NAME) ||
			!ft_strcmp(pointer->type, INDIRECT_LABEL_NAME)) &&
			!search_label(rows, pointer->content, *struct_content))
				return (NULL);
			flag = check_all_label_size(pointer, struct_content, flag);
			pointer = pointer->next;
		}
		flag = 0;
		struct_pointer = struct_pointer->next;
	}
	return ("very good");
}
