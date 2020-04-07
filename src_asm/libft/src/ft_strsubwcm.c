/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubwcm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:29:48 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/18 19:10:02 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubwcm(char *s, unsigned int start, size_t len)
{
	char	*new;

	new = ft_strsub(s, start, len);
	if (*s)
		ft_strdel(&s);
	return (new);
}
