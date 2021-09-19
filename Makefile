CC		= clang
CCFLAGS	= -Wall -Wextra -Werror
LIBFT	= make -C ./libft all
LINKS	= -I./libft -L./libft  -lft -I./minilibx -L./minilibx  -lmlx -lX11 \
-lXext -lm
NAME	= fdf
SANIT	= -fsanitize=address -g3
SRCS	= fdf_plot_map.c \
		  fdf_map_parser.c \
		  fdf.c fdf_plot_line.c \
		  fdf_keyboard_controller.c \
		  fdf_keys_arrow.c \
		  fdf_keys_wasd.c \
		  fdf_validation.c \
		  fdf_initialization.c \
		  fdf_plot_color.c\

OBJ		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	makelibft makelibx  $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LINKS)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I./libft

fdfrun:		makelibx makelibft $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LINKS) && ./$(NAME) 42.fdf

fdfsanit:	makelibx makelibft $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(SANIT) $(LINKS) && ./$(NAME) 42.fdf

fdfvalg:	makelibx makelibft $(OBJ)
	$(CC) $(SRCS) -o $(NAME) $(LINKS) && valgrind ./$(NAME) 42.fdf

clean:
	rm -f $(OBJ)
	make clean -C ./libft
	make clean -C ./minilibx

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make fclean -C ./minilibx

makelibft:
	make all -C ./libft

makelibx:
	make all -C ./minilibx

.PHONY:		all clean fclean re run fdf
