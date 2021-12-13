LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

MLX_PATH	= ./minilibx
MLX			= $(MLX_PATH)/libmlx_Linux.a

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
LINKS	= -I./libft -L./libft -lft -I./minilibx -L./minilibx -lmlx_Linux
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

$(NAME):	$(LIBFT) $(MLX) $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS) $(LINKS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@ -I./ -I./libft -I./minilibx

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./libft

run:		$(OBJDIR) $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LINKS) $(LIBS)
	./$(NAME) 42.fdf

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
	make all -C ./libft

$(MLX):
	make all -C ./minilibx

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY:		clean fclean re
