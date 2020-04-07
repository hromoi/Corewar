/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinwcm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:42 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 19:11:00 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinwcm(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (s1)
		ft_strdel(&s1);
	return (new);
}
