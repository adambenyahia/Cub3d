/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:27:06 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 03:40:53 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_args	*args_init(t_args *args)
{
	args->error = 0;
	args->map.grid = NULL;
	args->texture.we = NULL;
	args->texture.ea = NULL;
	args->texture.no = NULL;
	args->texture.so = NULL;
	args->texture.f = -1;
	args->texture.c = -1;
	args->map.x = 0;
	args->map.y = 0;
	args->key = 0;
	args->p.a = -1;
	args->p.x = -1;
	args->p.y = -1;
	args->p.count = 0;
	return (args);
}

int	clean_exit(t_args *args)
{
	(void)args;
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_args	args;

	args.mlx_p = mlx_init();
	checkext(argc, argv);
	if (filetostruct(argv[1], args_init(&args)) == -1)
		clean_exit(&args);
	operation_mlx(&args);
	return (0);
}
