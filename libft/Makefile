MAND	= ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum \
				ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr \
				ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd \
				ft_putendl_fd ft_putnbr_fd ft_striteri
BONUS		= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

CC      = cc
CCFLAGS = -Wall -Wextra -Werror
AR      = ar
ARFLAGS = rc

M_OBJ	= $(MAND:=.o)
B_OBJ	= $(BONUS:=.o)
NAME	= libft.a

all: $(NAME)

$(NAME): $(M_OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(M_OBJ)

bonus: $(B_OBJ) $(M_OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(M_OBJ) $(B_OBJ)

%.o: %.c libft.h 
	@$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	rm -f $(M_OBJ)
	rm -f $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus
