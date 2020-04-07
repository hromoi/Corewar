/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:08:07 by yperra-f          #+#    #+#             */
/*   Updated: 2018/12/19 16:02:24 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	char	*ft_help(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		k = i;
		while (s1[k] == s2[j] && s1[k] != '\0')
		{
			j++;
			k++;
		}
		if (s2[j] == '\0')
			return (s1 + i);
		else if (s1[k] != s2[j] && s2[j] != '\0')
			j = 0;
		i++;
	}
	if (s1[i] == '\0' && s2[j] != '\0')
		return (NULL);
	return (s1 + i);
}

char			*ft_strstr(const char *string1, const char *string2)
{
	size_t		i;
	size_t		j;
	char		*s1;
	char		*s2;

	s1 = (char *)string1;
	s2 = (char *)string2;
	i = ft_strlen(string1);
	j = ft_strlen(string2);
	if (*s1 == '\0' && *s2 == '\0')
		return (s2);
	if (*s2 != '\0' && *s1 == '\0')
		return (NULL);
	if (*s2 == '\0' && *s1 != '\0')
		return (s1);
	if (j > i)
		return (NULL);
	return (ft_help(s1, s2));
}
