/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:41:28 by beadam            #+#    #+#             */
/*   Updated: 2023/06/25 22:42:40 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	free_split(char **string, int ret)
{
	int	a;

	a = -1;
	while (string[++a])
		free(string[a]);
	free(string);
	return (ret);
}

static int	count_comma(char *str)
{
	int	a;
	int	count;

	a = -1;
	count = 0;
	while (str[++a])
	{
		if (str[a] == ',')
			count++;
	}
	return (count);
}

int	rgbstringtoint(char *str)
{
	char	**string;
	int		r;
	int		g;
	int		b;
	int		a;

	if (!str)
		return (-1);
	a = -1;
	if (count_comma(str) != 2)
		return (-1);
	while (str[++a])
		if ((str[a] > '9' || str[a] < '0') && str[a] != ',')
			return (-1);
	string = ft_split(str, ',');
	if (!string[0] || !string[1] || !string[2] || string[3])
		return (free_split(string, -1));
	r = ft_atoi(string[0]);
	g = ft_atoi(string[1]);
	b = ft_atoi(string[2]);
	if ((r | g | b) > 0xFF)
		return (free_split(string, -1));
	return (free_split(string, r << 16 | g << 8 | b));
}
