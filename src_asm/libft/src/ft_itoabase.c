/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:24:49 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/02 21:15:40 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_create_array_symb(void)
{
	char	*check;
	int		n;

	n = 0;
	if (!(check = (char *)ft_memalloc(16 * sizeof(char))))
		return (NULL);
	while (n < 10)
	{
		*check = n++;
		check++;
	}
	n = 65;
	while (n < 71)
	{
		*check = (char)n++;
		check++;
	}
	return (check);
}

static unsigned int	ft_preliminary_res(int value)
{
	unsigned int	res;

	if (value < 0)
		res = value * -1;
	else
		res = value;
	return (res);
}

static int			ft_sign_definition(int value, int base)
{
	int sign;

	sign = 0;
	if (value < 0)
	{
		if (base == 10)
			sign = 1;
	}
	return (sign);
}

char				*ft_itoabase(int value, int base)
{
	t_num_base		number;
	char			*check;
	char			*result;

	check = ft_create_array_symb();
	number.sign = ft_sign_definition(value, base);
	number.res = ft_preliminary_res(value);
	number.len = ft_strlen_base(value, base);
	result = (char*)malloc(sizeof(char) * number.len + number.sign + 1);
	result[number.sign + number.len--] = '\0';
	if (number.sign == 1 && base == 10)
		result[0] = '-';
	while (number.res)
	{
		result[number.len-- + number.sign] = check[number.res % base];
		number.res /= base;
	}
	return (result);
}
