/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 13:35:43 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 18:28:25 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parse(char *str, char *pattern)
{
	int			err;
	regex_t		reg1;
	regmatch_t	pm;

	err = regcomp(&reg1, pattern, REG_EXTENDED);
	if (err != 0)
	{
		regfree(&reg1);
		write(1, "error with regex in file interpretation.c\n", 42);
		return (0);
	}
	if (!regexec(&reg1, str, 0, &pm, 0))
	{
		regfree(&reg1);
		return (1);
	}
	regfree(&reg1);
	return (0);
}

void	interpretation(t_token *tokens, t_asm_content *content)
{
	if (parse(tokens->content, content->regex_array[LABEL]))
		tokens->type = ft_strdup(LABEL_NAME);
	else if (parse(tokens->content, content->regex_array[INSTRACTION]))
		tokens->type = ft_strdup(INSTRACTION_NAME);
	else if (parse(tokens->content, content->regex_array[REGISTER]))
		tokens->type = ft_strdup(REGISTER_NAME);
	else if (parse(tokens->content, content->regex_array[DIRECT_LABEL]))
		tokens->type = ft_strdup(DIRECT_LABEL_NAME);
	else if (parse(tokens->content, content->regex_array[DIRECT]))
		tokens->type = ft_strdup(DIRECT_NAME);
	else if (parse(tokens->content, content->regex_array[INDIRECT]))
		tokens->type = ft_strdup(INDIRECT_NAME);
	else if (parse(tokens->content, content->regex_array[INDIRECT_LABEL]))
		tokens->type = ft_strdup(INDIRECT_LABEL_NAME);
	else
		tokens->type = ft_strdup(UNCERTAIN_NAME);
}
