/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:11:20 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 19:11:39 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_left_trim(char **str)
{
	char	*new_str;
	char	*copy;

	copy = *str;
	new_str = NULL;
	if (!str)
		return (NULL);
	while (*copy && ft_isspace(*copy))
		copy++;
	new_str = ft_strdup(copy);
	ft_strdel(str);
	return (new_str);
}
