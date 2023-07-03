/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:08:36 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 02:56:07 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	loop(t_args *args)
{
	mlx_destroy_image(args->mlx_p, args->world.img);
	args->world.img = mlx_new_image(args->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	args->world.addr = mlx_get_data_addr(args->world.img, &args->world.bit_pp,
			&args->world.ll, &args->world.endian);
	keys(args);
	shoot(args);
	draw_3dwalls(args);
	mlx_put_image_to_window(args->mlx_p, args->win, args->world.img, 0, 0);
	return (0);
}

int	key_press(int key, t_args *args)
{
	if (key == 53)
		clean_exit(args);
	if (key == 123)
		args->key |= KL;
	if (key == 126 || key == 13)
		args->key |= KU;
	if (key == 124)
		args->key |= KR;
	if (key == 125 || key == 1)
		args->key |= KD;
	if (key == 0)
		args->key |= KSL;
	if (key == 2)
		args->key |= KSR;
	return (0);
}

int	key_release(int key, t_args *args)
{
	if (key == 53)
		clean_exit(args);
	if (key == 123)
		args->key &= ~KL;
	if (key == 126 || key == 13)
		args->key &= ~KU;
	if (key == 124)
		args->key &= ~KR;
	if (key == 125 || key == 1)
		args->key &= ~KD;
	if (key == 0)
		args->key &= ~KSL;
	if (key == 2)
		args->key &= ~KSR;
	return (0);
}

int	operation_mlx(t_args *args)
{
	args->win = mlx_new_window(args->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT,
			"cub3d");
	mlx_hook(args->win, 2, 0, key_press, args);
	mlx_hook(args->win, 3, 0, key_release, args);
	mlx_hook(args->win, 17, 0, clean_exit, NULL);
	args->world.img = mlx_new_image(args->mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	args->world.addr = mlx_get_data_addr(args->world.img, &args->world.bit_pp,
			&args->world.ll, &args->world.endian);
	mlx_loop_hook(args->mlx_p, loop, args);
	mlx_loop(args->mlx_p);
	return (0);
}
