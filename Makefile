LIBFT	= make -C ./libft all
LINKS	= -I./libft -L./libft  -lft -I./minilibx -L./minilibx  -lmlx -lX11 -lXext
SANIT	= -fsanitize=address -g3
SRCS	= fdf_plot_map.c fdf_map_parser.c fdf.c fdf_plot_line.c \
          fdf_keyboard_controller.c fdf_keys_arrow.c fdf_keys_wasd.c \
          fdf_validation.c fdf_initialization.c fdf_plot_color.c

fdf: makelibx makelibft
	clang $(SRCS) $(LINKS) -lm && ./a.out ./maps/test_maps/elem-col.fdf

fdftest: makelibx makelibft
	clang $(SRCS) $(LINKS) -lm && ./a.out ./maps/test_maps/50-4.fdf

fdfsanit: makelibx makelibft
	clang $(SRCS) $(SANIT) $(LINKS) -lm && ./a.out ./maps/test_maps/42.fdf

fdfvalg: makelibx makelibft
	clang $(SRCS) $(LINKS) -lm && valgrind  -s ./a.out ./maps/test_maps/42.fdf

horiz: makelibx makelibft
	clang testreadmap.c fdf_map_parser.c $(LINKS) && ./a.out 42.fdf

grid: makelibx makelibft
	gcc testgrid.c $(LINKS)

bresenham: makelibx makelibft
	gcc testbresenham.c $(LINKS)

parser: makelibx makelibft
	clang fdf_map_parser.c fdf_map_parser_main.c -I ./libft -L./libft -lft && ./a.out 42.fdf

iso: makelibft
	gcc testisometric.c $(LINKS)

clean:
	make clean -C ./libft
	make clean -C ./minilibx

fclean:
	make fclean -C ./libft
	make fclean -C ./minilibx

makelibft:
	make all -C ./libft

makelibx:
	make all -C ./minilibx
