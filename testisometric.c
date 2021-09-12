/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrictest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:55:09 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/12 00:35:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include "mlx.h"

void drawline(int x0, int y0, int x1, int y1, int *dump, int size_line)
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while(x < x1)
	{
		if(p >= 0)
		{
			dump[x + (y * size_line / 4)] = 0xFFFFFF;
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			dump[x + (y * size_line / 4)] = 0xFFFFFF;
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

void plotLine(int x0, int y0, int x1, int y1, int *dump, int size_line)
{
	int	dx, sx, dy, sy, err, e2;

	dx =  abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		//plot(x0, y0);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			dump[x0 + (y0 * size_line / 4)] = 0xFFFFFF;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			dump[x0 + (y0 * size_line / 4)] = 0xFFFFFF;
			y0 += sy;
		}
	}
}

//img[y + (x * size_line / 4)] = 0xFFFFFF;
//putpixel(x,y,7);

// static void iso(int *x, int *y, int z)
// {
//     int previous_x;
//     int previous_y;

//     previous_x = *x;
//     previous_y = *y;
//     *x = (previous_x - previous_y) * cos(0.523599);
//     *y = -z + (previous_x + previous_y) * sin(0.523599);
// }


int *put_line(int *img, int width, int height, int size_line)
{
	int	col;
	int	line;

	col = 20;
	line = 200;
	while (col <= width - OFFSET)
	{
		img[col + (line * size_line / 4)] = 0xFFFFFF;
		col++;
	}
	return (img);
}

int	iso(int carx, int cary, int mod)
{
	int	isox;
	int	isoy;

	isox = carx + cary;
	isoy = cary - carx / 2.0;

	carx = (isox - isoy) / 1.5;
	cary = isox / 3.0 + isoy / 1.5;
	if (mod == 1)
		return (isoy);
	return (isox);
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

	dump = put_line(dump, 800, 600, data.size_line);

	// for (int i = 0; i <= 800; i += 10)
	// 	drawline(i, 0, 800, 600, dump, data.size_line);

	// for (int i = 0; i <= 800; i += 10)
	// 	plotLine(i, 0, 800, 600, dump, data.size_line);

	int i = 0;
	int	j = 400;
	plotLine(i, j, 800, 400, dump, data.size_line);
	plotLine(iso(i, j, 0), iso(i, j, 1), iso(800, 400, 0), iso(800, 400, 1), dump, data.size_line);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "hello world!");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.win_img, 0, 0);

	mlx_loop(data.mlx_ptr);
}
