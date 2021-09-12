/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:58:02 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/12 00:20:49 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 600
# define OFFSET 120
# define INCREMENT 20

typedef struct s_img
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_img;
	int		bbp;
	int		size_line;
	int		end;
}	t_img;

#endif
