/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:58:02 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/12 12:00:22 by jofelipe         ###   ########.fr       */
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
# define OFFSET 120
# define INCREMENT 20

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

typedef struct s_map_data
{
	int	lines;
	int	line_len;
}	t_data;

int **parse_map(char *file, t_data *map_data);

#endif
