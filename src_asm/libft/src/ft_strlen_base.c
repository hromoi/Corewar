/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:42:03 by idunaver          #+#    #+#             */
/*   Updated: 2020/02/02 21:16:57 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_base(int value, int base)
{
	size_t len;

	len = (value == 0) ? 1 : 0;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}
