/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:34:33 by astanton          #+#    #+#             */
/*   Updated: 2018/11/29 18:09:17 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int n;
	int j;

	i = 0;
	if (str2[0] == '\0')
		return ((char*)&str1[0]);
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			n = 0;
			while (str2[j] && n == 0)
			{
				if (str1[i + j] != str2[j])
					n = 1;
				j++;
			}
			if (n == 0)
				return ((char*)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
