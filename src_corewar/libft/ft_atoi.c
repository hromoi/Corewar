/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:16:51 by astanton          #+#    #+#             */
/*   Updated: 2018/12/18 14:42:47 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	overload(long long nb, char c, char b, int n)
{
	if (ft_isdigit(b) || nb > 922337203685477580
		|| (nb == 922337203685477580 && (c - '0') > 7))
		return ((n == 1) ? 0 : -1);
	nb = nb * 10 + (c - '0');
	return ((n == 1) ? -nb : nb);
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	nb;
	int			n;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || (str[i] == '+'
			&& str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	n = ((str[i] == '-') ? 1 : 0);
	i += ((str[i] == '+' || str[i] == '-') ? 1 : 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb >= 922337203685477580 && str[i] >= '0' && str[i] <= '9')
			return (overload(nb, str[i], str[i + 1], n));
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return ((n == 1) ? -nb : nb);
}
