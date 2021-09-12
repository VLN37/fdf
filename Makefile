LIBFT	= make -C ./libft all
LINKS	= -L./libft -I./libft -lft -L./minilibx -I./minilibx -lmlx -lX11 -lXext

grid: makelibft
	gcc newwindow.c $(LINKS)

bresenham: makelibft
	gcc bresenhamtest.c $(LINKS)

clean:
	make clean -C ./libft

fclean:
	make fclean -C ./libft

makelibft:
	make all -C ./libft
