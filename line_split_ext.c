/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_split_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:38:48 by beadam            #+#    #+#             */
/*   Updated: 2023/06/25 22:38:49 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	you_aint_nothing_but_a(char a)
{
	if (a != 'W' && a != 'S' && a != 'N' && a != 'E' && a != 'C' && a != 'F')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	key_value(char *line, char **key, char **value)
{
	char	*newline;

	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (1);
	*key = line;
	if (you_aint_nothing_but_a(*line))
		return (0);
	while (*line && !ft_isspace(*line))
		line++;
	if (*line == '\0' || *line == '\n')
		return (*value = NULL, 0);
	*line = '\0';
	line++;
	while (*line && ft_isspace(*line))
		line++;
	*value = line;
	newline = ft_strchr(*value, '\n');
	if (newline != NULL)
		*newline = '\0';
	return (0);
}
