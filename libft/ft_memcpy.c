/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:52:07 by beadam            #+#    #+#             */
/*   Updated: 2021/11/09 16:07:55 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*_dst;
	char	*_src;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	_dst = (char *)dst;
	_src = (char *)src;
	while (i < n)
	{
		_dst[i] = _src[i];
		i++;
	}
	return (dst);
}
