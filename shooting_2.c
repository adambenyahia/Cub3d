/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:10:40 by ylamraou          #+#    #+#             */
/*   Updated: 2023/06/26 02:36:09 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int	has_wall_at(double x, double y, t_args *args)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = floor(x / TILE_SIZE);
	map_index_y = floor(y / TILE_SIZE);
	if (map_index_x < 0 || map_index_x > args->map.x - 1 || map_index_y < 0
		|| map_index_y > args->map.y - 1)
		return (-1);
	return (args->map.grid[map_index_y][map_index_x] == '1');
}

t_pos	find_wall(t_args *args, t_pos_norm *global, double *dist)
{
	while (global->intercept.x >= 0 && global->intercept.x
		/ TILE_SIZE <= args->map.x && global->intercept.y >= 0
		&& global->intercept.y / TILE_SIZE <= args->map.y)
	{
		if (has_wall_at(global->intercept.x, global->intercept.y, args))
		{
			global->pos.x = global->intercept.x;
			global->pos.y = global->intercept.y;
			return (*dist = distance(args->p.x, args->p.y, global->intercept.x,
					global->intercept.y), global->pos);
		}
		else if (has_wall_at(global->intercept.x,
				global->intercept.y, args) == -1)
			return (global->pos.x = INFINITY,
				global->pos.y = INFINITY, *dist = INFINITY, global->pos);
		else
		{
			global->intercept.x += global->step.x;
			global->intercept.y += global->step.y;
		}
	}
	return (global->pos.x = INFINITY, global->pos.y = INFINITY,
		*dist = INFINITY, global->pos);
}

t_pos	horizontal_intercept(t_args *args, t_ray *ray, double *dist)
{
	t_pos_norm	global;

	if (ray->ang > 0 && ray->ang < M_PI)
	{
		global.step.y = TILE_SIZE;
		global.intercept.y = floor(args->p.y / TILE_SIZE)
			* (TILE_SIZE) + TILE_SIZE;
	}
	else
	{
		global.step.y = -TILE_SIZE;
		global.intercept.y = floor(args->p.y / TILE_SIZE)
			* (TILE_SIZE) - 0.0001;
	}
	global.intercept.x = args->p.x + (global.intercept.y - args->p.y)
		/ tan(ray->ang);
	global.step.x = global.step.y / tan(ray->ang);
	return (find_wall(args, &global, dist));
}

t_pos	vertical_intercept(t_args *args, t_ray *ray, double *dist)
{
	t_pos_norm	global;

	if (ray->ang > M_PI_2 && ray->ang < 3 * M_PI_2)
	{
		global.step.x = -TILE_SIZE;
		global.intercept.x = floor(args->p.x / TILE_SIZE)
			* (TILE_SIZE) - 0.0001;
	}
	else
	{
		global.step.x = TILE_SIZE;
		global.intercept.x = floor(args->p.x / TILE_SIZE)
			* (TILE_SIZE) + TILE_SIZE;
	}
	global.intercept.y = args->p.y + (global.intercept.x - args->p.x)
		* tan(ray->ang);
	global.step.y = global.step.x * tan(ray->ang);
	return (find_wall(args, &global, dist));
}
