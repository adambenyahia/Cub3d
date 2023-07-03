/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:41:06 by beadam            #+#    #+#             */
/*   Updated: 2021/11/14 21:44:08 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;

	last = 0;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *) s;
		s++;
	}
	if (c == 0)
		return ((char *) s);
	else
		return (last);
}
