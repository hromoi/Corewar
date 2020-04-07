/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:58:50 by astanton          #+#    #+#             */
/*   Updated: 2018/12/13 13:50:27 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		len;
	int		sign;

	sign = (n >= 0) ? 0 : 1;
	nbr = n;
	len = 2;
	while ((nbr /= 10) != 0)
		len++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = (n >= 0) ? len : (len + 1);
	n = (n >= 0) ? n : -n;
	if (!(str = (char *)malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
