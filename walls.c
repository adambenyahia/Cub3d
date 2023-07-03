/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:04:17 by beadam            #+#    #+#             */
/*   Updated: 2023/06/25 20:04:18 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_hole(t_args args, int x, int y)
{
	if (args.map.grid[y][x] == ' ' || args.map.grid[y][x] == '\0')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_wall_extention(t_args args, int x, int y)
{
	if (is_player(args.map.grid[y][x]))
	{
		if (x == 0 || y == 0 || x == args.map.x - 1 || y == args.map.y - 1)
			return (printf("map leak line %d in map;\n", y + 1), 1);
		if (is_hole(args, x - 1, y) || is_hole(args, x + 1, y) || is_hole(args,
				x, y - 1) || is_hole(args, x, y + 1))
			return (printf("map leak line %d in map;\n", y + 1), 1);
	}
	if (args.map.grid[y][x] == '0')
	{
		if (x == 0 || y == 0 || x == args.map.x - 1 || y == args.map.y - 1)
			return (printf("map leak line %d in map;\n", y + 1), 1);
		if (is_hole(args, x - 1, y) || is_hole(args, x + 1, y) || is_hole(args,
				x, y - 1) || is_hole(args, x, y + 1))
			return (printf("map leak line %d in map;\n", y + 1), 1);
	}
	return (0);
}

int	check_walls(t_args args)
{
	int	x;
	int	y;

	y = -1;
	while (++y < args.map.y)
	{
		x = -1;
		while (++x < args.map.x)
		{
			if (check_wall_extention(args, x, y))
				return (1);
		}
	}
	return (0);
}
