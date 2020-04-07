/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:07:11 by astanton          #+#    #+#             */
/*   Updated: 2020/02/22 05:35:43 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_address(char *dst, int j, int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	dst[j++] = '0';
	dst[j++] = 'x';
	dst[j++] = hex[(i >> 12) & 0xf];
	dst[j++] = hex[(i >> 8) & 0xf];
	dst[j++] = hex[(i >> 4) & 0xf];
	dst[j++] = hex[i & 0xf];
	dst[j++] = ' ';
	dst[j++] = ':';
	dst[j++] = ' ';
}

void		dump_field(unsigned char *field)
{
	int		i;
	int		j;
	char	*hex;
	char	dst[14000];

	i = 0;
	j = 0;
	hex = "0123456789abcdef";
	while (i < MEM_SIZE)
	{
		if (i % LINE_LENGTH_DUMP == 0)
		{
			print_address(dst, j, i);
			j += 9;
		}
		dst[j++] = hex[(field[i] >> 4) & 0xf];
		dst[j++] = hex[field[i] & 0xf];
		dst[j++] = ' ';
		if (i % LINE_LENGTH_DUMP == LINE_LENGTH_DUMP - 1)
			dst[j++] = '\n';
		i++;
	}
	dst[j] = '\0';
	write(1, dst, ft_strlen(dst));
}
