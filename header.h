/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:31:14 by beadam            #+#    #+#             */
/*   Updated: 2023/06/26 03:39:21 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1024
# define Y_SENS 0.0392
# define DEG 0.0174533
# define KL 1
# define KU 2
# define KR 4
# define KD 8
# define KSR 16
# define KSL 32
# define TILE_SIZE 51
# define FOV 1.0471     // 60 * (M_PI / 180)
# define ABR 0.001022   //  (FOV / WINDOW_WIDTH)
# define DIST 886.81001 // (WINDOW_WIDTH / 2) / tan(FOV / 2)
# define SPEEDFACT 7

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bit_pp;
	int				ll;
	int				endian;
}					t_img;

typedef struct s_item_p
{
	double			x;
	double			y;
	double			dist_to_wall;
}					t_pos;

typedef struct s_ray
{
	double			ang;
	double			dist;
	double			x;
	double			y;
	int				hv;
}					t_ray;

typedef struct s_player
{
	double			x;
	double			y;
	double			a;
	double			dx;
	double			dy;
	int				count;
}					t_player;

typedef struct s_texture
{
	void			*no;
	void			*we;
	void			*so;
	void			*ea;
	int				f;
	int				c;
	int				x;
	int				y;
}					t_texture;

typedef struct s_key
{
	char			*key;
	char			*value;
}					t_key;

typedef struct s_token
{
	char			*token;
	struct s_token	*previous;
	struct s_token	*next;
	struct s_token	*tail;
}					t_token;

typedef struct s_map
{
	char			**grid;
	int				x;
	int				y;
}					t_map;

typedef struct s_args
{
	int				key;
	t_img			world;
	t_player		p;
	t_map			map;
	t_texture		texture;
	int				error;
	void			*mlx_p;
	void			*win;
	t_ray			ray[WINDOW_WIDTH];
	t_token			*tokens;
}					t_args;

typedef struct s_ray_norm
{
	t_ray			ray;
	t_pos			pos_h;
	t_pos			pos_v;
	t_pos			dist;
}					t_ray_norm;

typedef struct s_pos_norm
{
	t_pos			step;
	t_pos			intercept;
	t_pos			pos;

}					t_pos_norm;

int					key_value(char *line, char **key, char **value);
void				put_to_file(char *file, t_args *list);
void				print_list(t_token *list);
t_pos				horizontal_intercept(t_args *args, t_ray *ray,
						double *dist);
t_pos				vertical_intercept(t_args *args, t_ray *ray, double *dist);

//// line_split.c
char				**line_split(char const *s, char c);

//// ft_realloc.c
void				*ft_realloc(void *ptr, size_t newsize);

////// file.c
int					containsonlyset(const char *str);
int					filetostruct(char *file, t_args *args);
int					parcer2(t_token **tokens, t_args *args);
int					list_to_map(t_token *tokens, t_args *args);
void				checkext(int ac, char **av);

//// color.c
int					rgbstringtoint(char *str);

/// node.c
int					add_node(t_token **list, char *str);
void				deref_token2(t_token **tokens, t_token *node);

///mlx
int					operation_mlx(t_args *args);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int		mlx_get_color_at(void *img, int x, int y);

///rays
void				shoot(t_args *args);

///keys
int					keys(t_args *args);

///draw
void				draw_3dwalls(t_args *args);

///player
int					find_player(t_args *args);

///walls
int					check_walls(t_args args);

///exit
int					clean_exit(t_args *args);

#endif