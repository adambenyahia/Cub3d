/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 04:47:05 by beadam            #+#    #+#             */
/*   Updated: 2021/11/11 04:47:08 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	uc;
	unsigned char	*str;

	str = (unsigned char *) s;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return (str + i);
		i++;
	}
	if (c == 0 && n != 0)
		return (str + i);
	else
		return (0);
}
