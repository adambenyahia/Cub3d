/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:06:27 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 00:15:59 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	checkext(int ac, char **av)
{
	int	len;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		if (ft_strncmp(av[1] + len - 4, ".cub", 5))
		{
			printf("wrong extention\n");
			exit(0);
		}
		return ;
	}
	printf("usage mode: ./Cub3D [map file]");
	exit(0);
}

void	check_x(t_args *args, int ref)
{
	if (ref == 0)
	{
		if (args->map.grid[(int)(args->p.y) / TILE_SIZE][(int)(args->p.x
				- ((args->p.dx * 3))) / TILE_SIZE] != '1')
			args->p.x -= args->p.dx;
	}
	else if (ref == 1)
	{
		if (args->map.grid[(int)(args->p.y) / TILE_SIZE][(int)(args->p.x
				+ (args->p.dx * 3)) / TILE_SIZE] != '1')
			args->p.x += args->p.dx;
	}
	else if (ref == 2)
	{
		if (args->map.grid[(int)(args->p.y) / TILE_SIZE][(int)(args->p.x
				- (args->p.dy * 3)) / TILE_SIZE] != '1')
			args->p.x -= args->p.dy;
	}
	else if (ref == 3)
	{
		if (args->map.grid[(int)(args->p.y) / TILE_SIZE][(int)(args->p.x
				+ args->p.dy * 3) / TILE_SIZE] != '1')
			args->p.x += args->p.dy;
	}
}

void	check_y(t_args *args, int ref)
{
	if (ref == 0)
	{
		if (args->map.grid[(int)(args->p.y - (args->p.dy * 3))
			/ TILE_SIZE][(int)(args->p.x) / TILE_SIZE] != '1')
			args->p.y -= args->p.dy;
	}
	else if (ref == 1)
	{
		if (args->map.grid[(int)(args->p.y + args->p.dy * 3)
			/ TILE_SIZE][(int)(args->p.x) / TILE_SIZE] != '1')
			args->p.y += args->p.dy;
	}
	else if (ref == 2)
	{
		if (args->map.grid[(int)(args->p.y - (args->p.dx * 3))
			/ TILE_SIZE][(int)(args->p.x) / TILE_SIZE] != '1')
			args->p.y -= args->p.dx;
	}
	else if (ref == 3)
	{
		if (args->map.grid[(int)(args->p.y + (args->p.dx * 3))
			/ TILE_SIZE][(int)(args->p.x) / TILE_SIZE] != '1')
			args->p.y += args->p.dx;
	}
}

void	calcule_ang(t_args *args, int ref)
{
	if (ref == 0)
	{
		args->p.a -= Y_SENS;
		if (args->p.a < 0)
			args->p.a += 2 * M_PI;
		args->p.dx = cos(args->p.a) * SPEEDFACT;
		args->p.dy = sin(args->p.a) * SPEEDFACT;
	}
	else if (ref == 1)
	{
		args->p.a += Y_SENS;
		if (args->p.a > 2 * M_PI)
			args->p.a -= 2 * M_PI;
		args->p.dx = cos(args->p.a) * SPEEDFACT;
		args->p.dy = sin(args->p.a) * SPEEDFACT;
	}
}

int	keys(t_args *args)
{
	if (args->key & KL)
		calcule_ang(args, 0);
	if (args->key & KR)
		calcule_ang(args, 1);
	if (args->key & KU)
	{
		check_x(args, 1);
		check_y(args, 1);
	}
	if (args->key & KD)
	{
		check_x(args, 0);
		check_y(args, 0);
	}
	if (args->key & KSR)
	{
		check_x(args, 2);
		check_y(args, 3);
	}
	if (args->key & KSL)
	{
		check_x(args, 3);
		check_y(args, 2);
	}
	return (0);
}
