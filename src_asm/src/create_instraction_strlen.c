/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_instraction_strlen.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 20:40:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/03/11 20:41:17 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		create_instraction_strlen(void)
{
	int		length;

	length = ft_strlen(LIVE_NAME) +
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) +
	ft_strlen(LD_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) +
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(ST_NAME) + ft_strlen(DOLLAR) +
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(ADD_NAME) +
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) +
	ft_strlen(SUB_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) +
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(AND_NAME) + ft_strlen(DOLLAR) +
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(OR_NAME) +
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) +
	ft_strlen(XOR_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) +
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(ZJMP_NAME) + ft_strlen(DOLLAR) +
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(LDI_NAME) +
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) +
	ft_strlen(STI_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) +
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(FORK_NAME) + ft_strlen(DOLLAR) +
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(LLD_NAME) +
	ft_strlen(DOLLAR) + ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) +
	ft_strlen(LLDI_NAME) + ft_strlen(DOLLAR) + ft_strlen(PIPELINE) +
	ft_strlen(CIRCUMFLEXUS) + ft_strlen(LFORK_NAME) + ft_strlen(DOLLAR) +
	ft_strlen(PIPELINE) + ft_strlen(CIRCUMFLEXUS) + ft_strlen(AFF_NAME);
	return (length);
}

void	strcat_instraction(char *instraction)
{
	ft_strcat(instraction, LIVE_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LD_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, ST_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, ADD_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, SUB_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, AND_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
}

void	strcat_instraction_first(char *instraction)
{
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, OR_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, XOR_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, ZJMP_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LDI_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, STI_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, FORK_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
}

void	strcat_instraction_second(char *instraction)
{
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LLD_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LLDI_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, LFORK_NAME);
	ft_strcat(instraction, DOLLAR);
	ft_strcat(instraction, PIPELINE);
	ft_strcat(instraction, CIRCUMFLEXUS);
	ft_strcat(instraction, AFF_NAME);
}

char	*create_instraction_first_stage(t_asm_content *content)
{
	char	*instraction;

	if (!(instraction = ft_strnew(create_instraction_strlen())))
		error(content);
	strcat_instraction(instraction);
	strcat_instraction_first(instraction);
	strcat_instraction_second(instraction);
	return (instraction);
}
