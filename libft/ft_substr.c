/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:55:47 by beadam            #+#    #+#             */
/*   Updated: 2021/11/14 04:22:26 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	i = 0;
	ptr = malloc (len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	*ptr = 0;
	if (start > ft_strlen(s))
		return (ptr);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr [i] = 0;
	return (ptr);
}
