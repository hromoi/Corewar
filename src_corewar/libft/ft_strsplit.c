/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:07:15 by astanton          #+#    #+#             */
/*   Updated: 2018/12/13 18:20:58 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		str_nbr(const char *s, char c)
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbr++;
		i++;
	}
	return (nbr);
}

static	char	*string_create(char *new, const char *s, char c, int *i)
{
	int		start;
	int		j;
	int		len;

	len = 0;
	while (s[*i] != '\0' && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] != '\0' && s[*i] != c)
	{
		len++;
		(*i)++;
	}
	if (!(new = (char *)malloc(len + 1)))
		return (0);
	j = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		new[j] = s[start];
		start++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

static	void	delete_all(char **str)
{
	int		i;

	i = 0;
	while (str)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		boxes;
	char	**new;

	i = 0;
	if (!s)
		return (NULL);
	boxes = str_nbr(s, c);
	if (!(new = (char **)malloc(sizeof(*new) * (boxes + 1))))
		return (NULL);
	j = 0;
	while (j < boxes)
	{
		if (!(new[j] = string_create(new[j], s, c, &i)))
		{
			delete_all(new);
			return (NULL);
		}
		j++;
	}
	new[j] = 0;
	return (new);
}
