/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:06:33 by astanton          #+#    #+#             */
/*   Updated: 2018/11/29 18:10:43 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	if (str2[0] == '\0')
		return ((char *)&str1[0]);
	while (str1[i] != '\0' && i < len)
	{
		if (str1[i] - str2[0] == 0)
		{
			j = 1;
			n = 0;
			while (str2[j] != '\0' && (i + j) < len && n == 0)
			{
				if (str1[i + j] - str2[j] != 0)
					n = 1;
				j++;
			}
			if (str2[j] == '\0' && n == 0)
				return ((char *)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
