
NAME 	= cub3d
CC		= CC
CFLAGS 	= -Wall -Wextra -Werror

SRC		= line_split.c main.c keys.c mlx_operations.c line_split_ext.c draw.c ft_realloc.c parcer_ext.c file.c color.c node.c walls.c parcer.c additional.c shooting.c shooting_2.c
GNL 	= GNL/get_next_line.c GNL/get_next_line_utils.c
LIB 	= libft/libft.a
HEADER 	= header.h


OBJ = $(SRC:%.c=%.o)
MFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(LIB) $(NAME)

$(LIB):
	@ $(MAKE) -C libft
$(NAME): $(OBJ) $(HEADER)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIB) $(MFLAGS) $(GNL) -o $(NAME)
%.o: %.c $(HEADER)
	@ $(CC) $(CFLAGS) -c $< -o $@
clean:
	@ $(MAKE) -C libft clean
	@ rm -f $(OBJ)

fclean: clean
	@ $(MAKE) -C libft fclean
	@ rm -f $(NAME)

re: fclean all
