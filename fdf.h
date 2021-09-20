/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:58:02 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/20 15:38:14 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH 1800
# define HEIGHT 900
# define OFFSET 100
# define INCREMENT 30

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_K 107
# define KEY_J 106
# define OFFSETXX 0
# define OFFSETYY -600

typedef struct s_img
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_img;
	int		bbp;
	int		size_line;
	int		end;
	int		*dump;

	int		**map;
	int		lines;
	int		line_len;
	int		scale;
	int		max_height;

	int		offsetx;
	int		offsety;
	double	cos1;
	double	sin1;
}	t_img;

typedef struct s_coord
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		z0;
	int		z1;

	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
	int		lastcolor;
	float	colorfactor;
	float	heightfactor;
	int		iteration;
	int		iterationmax;
	int		pixellen;
}	t_coord;

int		**parse_map(char *file, t_img *img);
void	bresenham(t_coord xy, t_img img);
int		*plot_map_horizontal(t_img img);
int		*plot_map_vertical(t_img img);
int		screen_controller(int key, t_img *img);
int		keys_arrow(int key, t_img *img);
int		keys_wasd(int key, t_img *img);
void	init_image_data(t_img *img, char **argv);
int		get_color(t_coord *xy, t_img *img);
int		validation(int argc, char **argv);
void	set_scale(t_img *img, int **map);
int		fdf_keys_height(int key, t_img *img);

#endif
