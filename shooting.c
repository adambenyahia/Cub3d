/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:35:34 by ylamraou          #+#    #+#             */
/*   Updated: 2023/06/26 02:57:37 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

t_ray	cast_ray(t_args *args, int i)
{
	t_ray_norm	global;

	global.dist.x = INFINITY;
	global.dist.y = INFINITY;
	global.ray.ang = args->p.a - (FOV / 2) + (FOV * i / WINDOW_WIDTH);
	global.ray.ang = normalize_angle(global.ray.ang);
	global.pos_h = horizontal_intercept(args, &global.ray, &global.dist.x);
	global.pos_v = vertical_intercept(args, &global.ray, &global.dist.y);
	if (global.dist.x <= global.dist.y)
	{
		global.ray.hv = 1;
		global.ray.x = global.pos_h.x;
		global.ray.y = global.pos_h.y;
		global.ray.dist = global. dist.x * cos(global.ray.ang - args->p.a);
	}
	else
	{
		global.ray.hv = 0;
		global.ray.x = global.pos_v.x;
		global.ray.y = global.pos_v.y;
		global.ray.dist = global.dist.y * cos(global.ray.ang - args->p.a);
	}
	if (global.ray.dist == INFINITY)
		global.ray.dist = 0;
	return (global.ray);
}

void	shoot(t_args *args)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		args->ray[i] = cast_ray(args, i);
		i++;
	}
}
