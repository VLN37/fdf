LIBFT	= make -C ./libft all
LINKS	= -L./libft -I./libft -lft -L./minilibx -I./minilibx -lmlx -lX11 -lXext


all: libft
	gcc newwindow.c $(LINKS)

libft:
	make  all -C ./libft
	make  clean -C ./libft

