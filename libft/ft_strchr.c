/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:09:58 by beadam            #+#    #+#             */
/*   Updated: 2021/11/14 00:11:59 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char			*str;

	str = (unsigned char *) s;
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *) str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	else
		return (0);
}
