LIBFT	= make -C ./libft all
LINKS	= -I./libft -L./libft  -lft -I./minilibx -L./minilibx  -lmlx -lX11 -lXext
SANIT	= -fsanitize=address -g3
SRCS	= fdf_plotmap.c fdf_map_parser.c fdf.c fdf_bresenham.c

fdf: makelibft
	clang $(SRCS) $(LINKS) && ./a.out ./maps/test_maps/42.fdf

fdfsanit: makelibft
	clang $(SRCS) $(SANIT) $(LINKS) -lm && ./a.out ./maps/test_maps/42.fdf

fdfvalg: makelibft
	clang $(SRCS) $(LINKS) -lm && valgrind ./a.out ./maps/test_maps/42.fdf

horiz: makelibft
	clang testreadmap.c fdf_map_parser.c $(LINKS) && ./a.out 42.fdf

grid: makelibft
	gcc testgrid.c $(LINKS)

bresenham: makelibft
	gcc testbresenham.c $(LINKS)

parser: makelibft
	clang fdf_map_parser.c fdf_map_parser_main.c -I ./libft -L./libft -lft && ./a.out 42.fdf

iso: makelibft
	gcc testisometric.c $(LINKS)

clean:
	make clean -C ./libft

fclean:
	make fclean -C ./libft

makelibft:
	make all -C ./libft
