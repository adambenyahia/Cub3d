/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 02:16:16 by beadam            #+#    #+#             */
/*   Updated: 2021/11/11 02:16:18 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_size(int nbr)
{
	int	i;

	i = 1;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		is_neg;
	char	*result;

	is_neg = n < 0;
	i = (n <= 0) + nbr_size(n);
	result = malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	result[0] = '-';
	result[--i] = 0;
	if (!is_neg)
		n *= -1;
	while (--i >= is_neg)
	{
		result[i] = (n % 10 * -1) + '0';
		n /= 10;
	}
	return (result);
}
