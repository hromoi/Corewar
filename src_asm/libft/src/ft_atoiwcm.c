/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiwcm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:58 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/16 16:30:36 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoiwcm(char *str)
{
	int	result;

	result = atoi(str);
	if (*str)
		ft_strdel(&str);
	return (result);
}
