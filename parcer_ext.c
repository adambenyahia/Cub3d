/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:30:32 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 02:37:48 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	*cleaner(t_args *args, char *texture)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(args->mlx_p, texture, &args->texture.x,
			&args->texture.y);
	free(texture);
	if (args->texture.x != TILE_SIZE || args->texture.y != TILE_SIZE)
		return (printf("XPM size execption\n"), NULL);
	return (tmp);
}

static int	try_open(t_args *args)
{
	args->texture.so = cleaner(args, (char *)args->texture.so);
	args->texture.ea = cleaner(args, (char *)args->texture.ea);
	args->texture.no = cleaner(args, (char *)args->texture.no);
	args->texture.we = cleaner(args, (char *)args->texture.we);
	if (!args->texture.ea || !args->texture.we || !args->texture.so
		|| !args->texture.no || args->texture.c == -1 || args->texture.f == -1)
		return (printf("check textures and colors formats\n"), 1);
	if (find_player(args))
		return (1);
	args->p.dx = cos(args->p.a) * SPEEDFACT;
	args->p.dy = sin(args->p.a) * SPEEDFACT;
	return (0);
}

static int	map_dimentions(t_args *args, t_token *tokens)
{
	int		current;
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (containsonlyset(tmp->token))
			return (-1);
		current = ft_strlen(tmp->token);
		if (tmp->token[current - 1] == '\n')
			tmp->token[current - 1] = '\0';
		if (current > args->map.x)
			args->map.x = current - 1;
		args->map.y++;
		tmp = tmp->next;
	}
	args->map.grid = malloc(sizeof(char *) * args->map.y + 1);
	return (0);
}

int	list_to_map(t_token *tokens, t_args *args)
{
	int		current;
	t_token	*tmp;

	if (map_dimentions(args, tokens))
		return (-1);
	tmp = tokens;
	current = 0;
	while (tmp)
	{
		args->map.grid[current++] = ft_realloc(tmp->token, args->map.x);
		tmp = tmp->next;
	}
	args->map.grid[current] = NULL;
	if (check_walls(*args))
		return (-1);
	if (try_open(args))
		return (-1);
	return (0);
}
