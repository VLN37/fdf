#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define OFFSET 80
#define INCREMENT 5
typedef struct s_img
{
	void *mlx_ptr;
	void *win_ptr;
	void *win_img;
	int	bbp;
	int	size_line;
	int	end;
}	t_img;

#endif
