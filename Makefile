LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.addprefix

MLX_PATH	= ./minilibx
MLX			= $(MLX_PATH)/libmlx_Linux.a

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
LIBFT	= make -C ./libft all
LINKS	= -I./ -I./libft
LIBS	= -lX11 -lXext -lm
NAME	= fdf
SANIT	= -fsanitize=address -g3

HEADER	= fdf.h
SRCDIR	= src
OBJDIR	= obj
SRCFILES= fdf_plot_map.c \
		  fdf_map_parser.c \
		  fdf.c fdf_plot_line.c \
		  fdf_keyboard_controller.c \
		  fdf_keys_arrow.c \
		  fdf_keys_wasd.c \
		  fdf_validation.c \
		  fdf_initialization.c \
		  fdf_plot_color.c \
		  fdf_keys_height.c \

SRC		= $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJ		= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all:	$(NAME)

$(NAME):	$(OBJDIR) $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) $(LIBS) $(LIBFT) $(MLX) -o $(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@ -I./ -I./libft -I./minilibx

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./libft

fdfrun:		$(OBJDIR) $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKS) $(LIBS)
	./$(NAME) 42.fdf

fdfsanit:	$(OBJDIR) $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(SANIT) $(LINKS) $(LIBS)
	./$(NAME) 42.fdf

fdfvalg:	$(OBJDIR) $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKS) $(LIBS)
	valgrind ./$(NAME) 42.fdf

parsertest:
	clang fdf_map_parser_main.c fdf_map_parser.c -L ./libft -lft -I ./libft && ./a.out 42.fdf

clean:
	rm -f $(OBJ)
	rm -rf obj
	make clean -C ./libft
	make clean -C ./minilibx

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

$(LIBFT):
	make all -C $(LIBFT_PATH)

$(MLX):
	make all -C $(MLX_PATH)

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY:		all clean fclean re fdf
