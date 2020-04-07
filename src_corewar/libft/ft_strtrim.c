/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:28:14 by astanton          #+#    #+#             */
/*   Updated: 2018/12/13 09:57:02 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		j;
	int		i;
	char	*str;

	if (s)
	{
		len = ft_strlen(s);
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
		i = 0;
		while (len != 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		if (!(str = malloc(len - i + 1)))
			return (NULL);
		j = 0;
		i -= 1;
		while (s[++i] && i < len)
		{
			str[j++] = s[i];
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}
