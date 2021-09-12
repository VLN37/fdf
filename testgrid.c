/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:29:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/12 00:36:21 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	*put_horizontal_line(int *img, int width, int height, int size_line)
{
	int	col;
	int	line;

	col = OFFSET;
	line = OFFSET;
	while (line <= height - OFFSET)
	{
		while (col <= width - OFFSET)
		{
			img[col + (line * size_line / 4)] = 0xFFFFFF;
			col++;
		}
		line += INCREMENT;
		col = OFFSET;
	}
	return (img);
}

int	*put_vertical_line(int *img, int width, int height, int size_line)
{
	int	col;
	int	line;

	col = OFFSET;
	line = OFFSET;
	while (col <= width - OFFSET)
	{
		while (line <= height - OFFSET)
		{
			img[col + (line * (size_line / 4))] = 0xFFFFFF;
			line++;
		}
		col += INCREMENT;
		line = OFFSET;
	}
	return (img);
}

int	main(void)
{
	t_img	data;
	int		*dump;
	int		y;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	dump = (int *)mlx_get_data_addr(data.win_img, \
	&data.bbp, &data.size_line, &data.end);
	dump = put_horizontal_line(dump, WIDTH, HEIGHT, data.size_line);
	dump = put_vertical_line(dump, WIDTH, HEIGHT, data.size_line);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "hello world!");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.win_img, 0, 0);
	mlx_loop(data.mlx_ptr);
}

// void drawline(int x0, int y0, int x1, int y1)
// {
// 	int dx, dy, p, x, y;

// 	dx=x1-x0;
// 	dy=y1-y0;

// 	x=x0;
// 	y=y0;

// 	p=2*dy-dx;

// 	while(x<x1)
// 	{
// 	if(p>=0)
// 	{
// 		putpixel(x,y,7);
// 		y=y+1;
// 		p=p+2*dy-2*dx;
// 	}
// 	else
// 	{
// 		putpixel(x,y,7);
// 		p=p+2*dy;
// 	}
// 	x=x+1;
// 	}
// }
