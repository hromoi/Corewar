/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:20:14 by idunaver          #+#    #+#             */
/*   Updated: 2020/01/26 15:09:54 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_right_trim(char *str)
{
	if (!str)
		return ;
	str += ft_strlen(str);
	while (*str == '\0' || ft_isspace(*str))
		str--;
	*(str + 1) = '\0';
}
