#to compile the library
#gcc -Wall -Wextra - Werror -c ft* && ar rc libft.a *.o

#to compile the file with the library and includes
#gcc -Wall -Wextra -Werror main.c -L. -lft -I ./includes/libft.h

#SRCS		= $(wildcard ft_*.c)

SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
              ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
              ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
              ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
              ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
              ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
              ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
              ft_strnchr.c get_next_line.c

SRCSBONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
              ft_lstlast.c ft_lstlast.c ft_lstadd_back.c \
              ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
              ft_lstmap.c \

OBJ			= ${SRCS:.c=.o}
OBJBONUS	= ${SRCSBONUS:.c=.o}

NAME		= libft.a
CC			= clang
AR			= ar
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= rcs

all:		${NAME}

${NAME}:	${OBJ}
			${AR} ${ARFLAGS} ${NAME} ${OBJ}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus:		${NAME} ${OBJBONUS}
			${AR} ${ARFLAGS} ${NAME} ${OBJBONUS}

so:
			$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
			gcc -nostartfiles -shared -o libft.so $(OBJ)

clean:
			${RM} ${OBJ} ${OBJBONUS}

fclean:		clean
			${RM} ${NAME}

run:		all clean

re:			fclean all

.PHONY:		all clean fclean re run
