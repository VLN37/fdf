/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:58:02 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/13 04:54:24 by jofelipe         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define OFFSET 100
# define INCREMENT 30

typedef struct s_img
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_img;
	int		*dump;
	int		bbp;
	int		size_line;
	int		end;
}	t_img;

typedef struct s_coord
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	z0;
	int	z1;
}	t_coord;

typedef struct s_map_data
{
	int	lines;
	int	line_len;
}	t_data;

int **parse_map(char *file, t_data *map_data);

#endif
