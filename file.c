/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:43:34 by beadam            #+#    #+#             */
/*   Updated: 2023/06/25 22:49:34 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	assigne_value(t_args *args, double x, double y, double angle)
{
	args->p.x = x * TILE_SIZE + TILE_SIZE / 2;
	args->p.y = y * TILE_SIZE + TILE_SIZE / 2;
	args->p.a = angle;
	args->p.count++;
}

int	find_player(t_args *args)
{
	int	x;
	int	y;

	y = -1;
	while (++y < args->map.y)
	{
		x = -1;
		while (++x < args->map.x && args->p.count < 2)
		{
			if (args->map.grid[y][x] == 'S')
				assigne_value(args, x, y, M_PI / 2);
			if (args->map.grid[y][x] == 'W')
				assigne_value(args, x, y, M_PI);
			if (args->map.grid[y][x] == 'N')
				assigne_value(args, x, y, 3 * M_PI / 2);
			if (args->map.grid[y][x] == 'E')
				assigne_value(args, x, y, 0);
		}
	}
	if (args->p.count != 1)
		return (printf("player position exeption\n"), -1);
	return (0);
}

int	containsonlyset(const char *str)
{
	while (*str)
	{
		if (!ft_strchr("10EWSN \n", *str))
			return (1);
		str++;
	}
	return (0);
}

int	filetostruct(char *file, t_args *args)
{
	int		fd;
	char	*buff;

	args->tokens = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(file), -1);
	buff = get_next_line(fd);
	while (buff)
	{
		add_node(&args->tokens, buff);
		buff = get_next_line(fd);
	}
	close(fd);
	if (parcer2(&args->tokens, args) == -1)
		return (printf("%s: BAD FORMAT\n", file), -1);
	if (!args->map.grid)
	{
		printf("%s: empty file (no map or configuration)\n", file);
		exit(0);
	}
	return (0);
}
