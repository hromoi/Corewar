/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <astanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:41:46 by astanton          #+#    #+#             */
/*   Updated: 2019/12/03 13:56:17 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	size_t			m;
	unsigned char	*tmp;
	unsigned char	*tmp_src;

	m = n / sizeof(unsigned int);
	i = 0;
	while (i < m)
	{
		((unsigned int*)dst)[i] = ((unsigned int*)src)[i];
		i++;
	}
	tmp = (unsigned char *)dst + i * 4;
	tmp_src = (unsigned char *)src + i * 4;
	n = n % 4;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp_src[i];
		i++;
	}
	return (dst);
}
