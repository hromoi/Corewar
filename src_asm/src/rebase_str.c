/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:13:59 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/09 21:04:28 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*rebase_str_first_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	temp = ft_strchr(content, DIRECT_CHAR);
	temp1 = ft_strsub(content, 0, ft_strlen(content) - ft_strlen(temp));
	str_cat = ft_strjoinwcm(temp1, SPACE);
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}

char	*rebase_str_second_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	temp = ft_strchr(content, LABEL_CHAR) + 1;
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, SPACE);
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}

char	*rebase_str_third_case(char *content)
{
	char *result;
	char *str_cat;
	char *temp;
	char *temp1;

	if (!(temp = ft_strchr(content, COMMENT_CHAR)))
		temp = ft_strchr(content, ALT_COMMENT_CHAR);
	temp1 = ft_strsub(content, 0, strlen(content) - strlen(temp));
	str_cat = ft_strjoinwcm(temp1, SPACE);
	result = ft_strjoinwcm(str_cat, temp);
	ft_strdel(&content);
	return (result);
}
