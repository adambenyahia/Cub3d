/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:02:20 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 02:33:25 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_color(t_args *args, int x, int y, int size)
{
	int		tx;
	int		ty;
	void	*texture;

	if (!args->ray[x].hv)
	{
		if (args->ray[x].ang < (3 * M_PI / 2) && args->ray[x].ang > M_PI / 2)
			texture = args->texture.we;
		else
			texture = args->texture.ea;
		tx = (int)args->ray[x].y % TILE_SIZE;
		ty = ((y - ((WINDOW_HEIGHT / 2) - (size / 2))))
			* ((double)(double)TILE_SIZE / (double)size);
	}
	else
	{
		if (args->ray[x].ang < M_PI && args->ray[x].ang > 0)
			texture = args->texture.so;
		else
			texture = args->texture.no;
		tx = (int)args->ray[x].x % TILE_SIZE;
		ty = ((y - ((WINDOW_HEIGHT / 2) - (size / 2))))
			* ((double)(double)TILE_SIZE / (double)size);
	}
	return (mlx_get_color_at(texture, tx, ty));
}

static void	draw_line2(t_args *args, int i, double j)
{
	int	start;
	int	end;
	int	index;

	start = (WINDOW_HEIGHT / 2) - j / 2;
	end = (WINDOW_HEIGHT / 2) + j / 2;
	index = -1;
	while (++index < WINDOW_HEIGHT)
	{
		if (index < start)
			my_mlx_pixel_put(&(args->world), i, index, args->texture.c);
		else if (index < end)
		{
			my_mlx_pixel_put(&(args->world), i, index, get_color(args, i, index,
					j));
		}
		else
			my_mlx_pixel_put(&(args->world), i, index, args->texture.f);
	}
}

void	draw_3dwalls(t_args *args)
{
	int		i;
	double	j;

	i = 0;
	j = 0;
	while (i < WINDOW_WIDTH)
	{
		j = TILE_SIZE / args->ray[i].dist * DIST;
		draw_line2(args, i, j);
		i++;
	}
}
