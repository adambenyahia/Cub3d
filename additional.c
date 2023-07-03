/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:39:31 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 02:33:07 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	mlx_get_color_at(void *img, int x, int y)
{
	char			*data_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	unsigned int	color;

	data_ptr = (char *)mlx_get_data_addr(img, &bits_per_pixel, &size_line,
			&endian);
	color = *(unsigned int *)(data_ptr + (y * size_line) + (x * (bits_per_pixel
					/ 8)));
	return (color);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->ll + x * (img->bit_pp / 8));
	*(unsigned int *)dst = color;
}
