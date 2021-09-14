LIBFT	= make -C ./libft all
LINKS	= -L./libft -I./libft -lft -L./minilibx -I./minilibx -lmlx -lX11 -lXext
SANIT	= -fsanitize=address -g3

vert: makelibft

horiz: makelibft
	clang testreadmap.c map_parser.c $(LINKS) && ./a.out 42.fdf

grid: makelibft
	gcc testgrid.c $(LINKS)

bresenham: makelibft
	gcc testbresenham.c $(LINKS)

parser: makelibft
	clang map_parser.c map_parser_main.c -I ./libft -L./libft -lft && ./a.out 42.fdf

iso: makelibft
	gcc testisometric.c $(LINKS)

clean:
	make clean -C ./libft

fclean:
	make fclean -C ./libft

makelibft:
	make all -C ./libft
