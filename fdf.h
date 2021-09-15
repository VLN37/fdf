/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:58:02 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/15 04:46:59 by jofelipe         ###   ########.fr       */
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
}	t_img;

typedef struct s_coord
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	z0;
	int	z1;

	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_coord;

// typedef struct s_map_data
// {
// 	int	lines;
// 	int	line_len;
// 	int	scale;
// 	int	max_height;
// }	t_data;

int **parse_map(char *file, t_img *img);

#endif
