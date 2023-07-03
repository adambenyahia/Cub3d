/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 04:45:11 by beadam            #+#    #+#             */
/*   Updated: 2021/11/11 04:45:16 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*_dst;
	char			*_src;
	unsigned int	i;

	if (dst == 0 && src == 0)
		return (0);
	_dst = (char *) dst;
	_src = (char *) src;
	if (_dst > _src)
	{
		i = n;
		while (i--)
			_dst[i] = _src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			_dst[i] = _src[i];
			i++;
		}
	}
	return (dst);
}
