/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plotmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:36:05 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/14 04:20:27 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	plotLine(int x0, int y0, int x1, int y1, int *dump, int size_line)
{
	int	dx, sx, dy, sy, err, e2;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		//plot(x0, y0);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			if (x0 < WIDTH && y0 < HEIGHT )
				dump[x0 + (y0 * size_line / 4)] = 0xFFFFFF;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			if (x0 < WIDTH && y0 < HEIGHT )
				dump[x0 + (y0 * size_line / 4)] = 0xFFFFFF;
			y0 += sy;
		}
	}
}

t_coord	iso(t_coord coord)
{
	int	isox0;
	int	isoy0;
	int	isox1;
	int	isoy1;

	isox0 = coord.x0 - coord.y0;
	isoy0 = (coord.x0 + coord.y0) / 2.0;
	isox1 = coord.x1 - coord.y1;
	isoy1 = (coord.x1 + coord.y1) / 2.0;

	coord.x0 = isox0;
	coord.y0 = isoy0;
	coord.x1 = isox1;
	coord.y1 = isoy1;
	// isox = (carx - cary) * cos(0.523599); // pi / 3
	// isoy = (carx + cary) * sin(0.523599); //
	return (coord);
}

t_coord	get_coord_horizontal(t_coord coord, int **map, int x, int y)
{
	// coord.z0 = coord.z1 - map[x][y];
	// coord.z1 = map[x][y + 1];
	// coord.z0 = map[x][y];
	// coord.z1 = map[x][y + 1];
	coord.y0 = ((-map[x][y]) + (x * INCREMENT + OFFSET));
	coord.x0 = ((-map[x][y]) + (y * INCREMENT + OFFSET));
	coord.y1 = ((-map[x][y + 1]) + (x * INCREMENT + OFFSET));
	coord.x1 = ((-map[x][y + 1]) + (y * INCREMENT + INCREMENT + OFFSET));

	return(coord);
}

t_coord	get_coord_vertical(t_coord coord, int **map, int x, int y)
{
	//coord.z0 = coord.z1 - map[x][y];
	//coord.z1 = map[x][y + 1];
	// coord.z0 = map[x][y];
	// coord.z1 = map[x + 1][y];
	coord.y0 = ((-map[x][y]) + (x * INCREMENT + OFFSET));
	coord.x0 = ((-map[x][y]) + (y * INCREMENT + OFFSET));
	coord.y1 = ((-map[x + 1][y]) + (x * INCREMENT + INCREMENT + OFFSET));
	coord.x1 = ((-map[x + 1][y]) + (y * INCREMENT + OFFSET));

	return(coord);
}

int	*plot_map_horizontal(int *dump, int **map, int	size_line, t_data map_data)
{
	int	x;
	int	y;
	t_coord coord;

	coord.z0 = 0;
	coord.z1 = 0;
	x = 0;
	y = 0;
	while (x < map_data.lines - 1)
	{
		while (y < map_data.line_len - 1)
		{
			coord = get_coord_horizontal(coord, map, x, y);
			coord = iso(coord);
			plotLine(coord.x0 + 400, coord.y0 + 200, coord.x1 + 400, coord.y1 + 200, dump, size_line);
			y++;
		}
		x++;
		y = 0;
	}
	return (dump);
}

int	*plot_map_vertical(int *dump, int **map, int size_line, t_data map_data)
{
	int	x;
	int	y;
	t_coord coord;

	coord.z0 = 0;
	coord.z1 = 0;
	x = 0;
	y = 0;

	while (x < map_data.lines - 2)
	{
		while (y < map_data.line_len)
		{
			coord = get_coord_vertical(coord, map, x, y);
			coord = iso(coord);
			plotLine(coord.x0 + 400, coord.y0 + 200, coord.x1 + 400, coord.y1 + 200, dump, size_line);
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
	t_data	map_data;
	int		**map;
	int		*dump;

	img.mlx_ptr = mlx_init();
	if (!img.mlx_ptr)
		return (1);
	img.win_img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);

	map = parse_map(argv[1], &map_data);
	dump = (int *)mlx_get_data_addr(img.win_img, \
	&img.bbp, &img.size_line, &img.end);

	printf("%d %d\n", map_data.lines, map_data.line_len);
	dump = plot_map_horizontal(dump, map, img.size_line, map_data);
	dump = plot_map_vertical(dump, map, img.size_line, map_data);

	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "hello world!");
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);

	mlx_loop(img.mlx_ptr);
}