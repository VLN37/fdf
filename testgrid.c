/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:29:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/15 05:09:14 by jofelipe         ###   ########.fr       */
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
	t_img	img;

	img.mlx_ptr = mlx_init();
	if (!img.mlx_ptr)
		return (1);
	img.win_img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.dump = (int *)mlx_get_data_addr(img.win_img, \
	&img.bbp, &img.size_line, &img.end);
	img.dump = put_horizontal_line(img.dump, WIDTH, HEIGHT, img.size_line);
	img.dump = put_vertical_line(img.dump, WIDTH, HEIGHT, img.size_line);
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "hello world!");
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);
	mlx_loop(img.mlx_ptr);
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
