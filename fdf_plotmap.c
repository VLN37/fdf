/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plotmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:36:05 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/15 04:53:51 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	gradient(int color)
{
	int red;

	red = 0x000101;
	color -= red * 255;
	return (color);

}

t_coord	init_bresenham(t_coord xy)
{
	xy.x0 += 400;
	xy.x1 += 400;
	xy.y1 += 200;
	xy.y0 += 200;
	xy.dx = abs(xy.x1 - xy.x0);
	xy.dy = -abs(xy.y1 - xy.y0);
	// xy.sx = xy.x0 < xy.x1 ? 1 : -1;
	// xy.sy = xy.y0 < xy.y1 ? 1 : -1;
	if (xy.x0 < xy.x1)
		xy.sx = 1;
	else
		xy.sx = -1;
	if (xy.y0 < xy.y1)
		xy.sy = 1;
	else
		xy.sy = -1;
	xy.err = xy.dx + xy.dy;

	return (xy);
}

t_coord	bresenham(t_coord xy, t_img img)
{
	xy = init_bresenham(xy);

	while (1)
	{
		if (xy.x0 == xy.x1 &&xy. y0 == xy.y1)
			break ;
		xy.e2 = 2 * xy.err;
		if (xy.e2 >= xy.dy)
		{
			xy.err += xy.dy;
			if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT )
				img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] = gradient(0xFFFFFF);
			xy.x0 += xy.sx;
		}
		if (xy.e2 <= xy.dx)
		{
			xy.err += xy.dx;
			if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT )
				img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] = gradient(0xFFFFFF);
			xy.y0 += xy.sy;
		}
	}
	return (xy);
}

t_coord	iso(t_coord coord)
{
	int	isox0;
	int	isoy0;
	int	isox1;
	int	isoy1;

	isox0 = coord.x0 - coord.y0;
	isoy0 = (coord.x0 + coord.y0) / 1.5;
	isox1 = coord.x1 - coord.y1;
	isoy1 = (coord.x1 + coord.y1) / 1.5;

	// isox0 = (coord.x0 - coord.y0) * cos(0.523599);
	// isoy0 = (coord.x0 - coord.y0) * sin(0.523599);
	// isox1 = (coord.x1 - coord.y1) * cos(0.523599);
	// isoy1 = (coord.x1 - coord.y1) * sin(0.523599);

	coord.x0 = isox0;
	coord.y0 = isoy0;
	coord.x1 = isox1;
	coord.y1 = isoy1;
	return (coord);
}

t_coord	get_coord_horizontal(t_coord coord, int **map, int x, int y, int scale)
{
	// coord.z0 = coord.z1 - map[x][y];
	// coord.z1 = map[x][y + 1];
	// coord.z0 = map[x][y];
	// coord.z1 = map[x][y + 1];
	coord.y0 = ((-map[x][y]) + (x * scale + OFFSET));
	coord.x0 = ((-map[x][y]) + (y * scale + OFFSET));
	coord.y1 = ((-map[x][y + 1]) + (x * scale + OFFSET));
	coord.x1 = ((-map[x][y + 1]) + (y * scale + scale + OFFSET));

	return(coord);
}

t_coord	get_coord_vertical(t_coord coord, int **map, int x, int y, int scale)
{
	//coord.z0 = coord.z1 - map[x][y];
	//coord.z1 = map[x][y + 1];
	// coord.z0 = map[x][y];
	// coord.z1 = map[x + 1][y];
	coord.y0 = ((-map[x][y]) + (x * scale + OFFSET));
	coord.x0 = ((-map[x][y]) + (y * scale + OFFSET));
	coord.y1 = ((-map[x + 1][y]) + (x * scale + scale + OFFSET));
	coord.x1 = ((-map[x + 1][y]) + (y * scale + OFFSET));

	return(coord);
}

int	*plot_map_horizontal(int *dump, int **map, int	size_line, t_img img)
{
	int	x;
	int	y;
	t_coord coord;

	coord.z0 = 0;
	coord.z1 = 0;
	x = 0;
	y = 0;
	while (x < img.lines - 1)
	{
		while (y < img.line_len - 1)
		{
			coord = get_coord_horizontal(coord, map, x, y, img.scale);
			coord = iso(coord);
			coord = bresenham(coord, img);
			y++;
		}
		x++;
		y = 0;
	}
	return (dump);
}

int	*plot_map_vertical(int *dump, int **map, int size_line, t_img img)
{
	int	x;
	int	y;
	t_coord coord;

	coord.z0 = 0;
	coord.z1 = 0;
	x = 0;
	y = 0;

	while (x < img.lines - 2)
	{
		while (y < img.line_len)
		{
			coord = get_coord_vertical(coord, map, x, y, img.scale);
			coord = iso(coord);
			coord = bresenham(coord, img);
			y++;
		}
		x++;
		y = 0;
	}
	return (dump);
}

int	main(int argc, char **argv)
{
	t_img	img;

	img.mlx_ptr = mlx_init();
	if (!img.mlx_ptr)
		return (1);
	img.win_img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);

	img.map = parse_map(argv[1], &img);
	img.dump = (int *)mlx_get_data_addr(img.win_img, \
	&img.bbp, &img.size_line, &img.end);

	plot_map_horizontal(img.dump, img.map, img.size_line, img);
	plot_map_vertical(img.dump, img.map, img.size_line, img);

	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "hello world!");
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);

	mlx_loop(img.mlx_ptr);
}
