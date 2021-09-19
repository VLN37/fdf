/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:36:05 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 13:29:06 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

// isox0 = round((coord.x0 - coord.y0) * cos(0.523599));
// isoy0 = round((coord.x0 + coord.y0) * sin(0.523599));
// isox1 = round((coord.x1 - coord.y1) * cos(0.523599));
// isoy1 = round((coord.x1 + coord.y1) * sin(0.523599));
static t_coord	iso(t_coord coord, t_img img)
{
	int	isox0;
	int	isoy0;
	int	isox1;
	int	isoy1;

	isox0 = (coord.x0 - coord.y0) / img.cos1;
	isoy0 = (coord.x0 + coord.y0) / img.sin1;
	isox1 = (coord.x1 - coord.y1) / img.cos1;
	isoy1 = (coord.x1 + coord.y1) / img.sin1;
	coord.x0 = isox0;
	coord.y0 = isoy0;
	coord.x1 = isox1;
	coord.y1 = isoy1;
	return (coord);
}

static t_coord	get_coord_horiz(t_coord xy, int **map, int x, int y, int scale)
{
	xy.z0 = map[x][y];
	xy.z1 = map[x][y + 1];
	xy.y0 = ((-map[x][y]) + (x * scale + OFFSETYY));
	xy.x0 = ((-map[x][y]) + (y * scale + OFFSETXX));
	xy.y1 = ((-map[x][y + 1]) + (x * scale + OFFSETYY));
	xy.x1 = ((-map[x][y + 1]) + (y * scale + scale + OFFSETXX));
	return (xy);
}

static t_coord	get_coord_vert(t_coord xy, int **map, int x, int y, int scale)
{
	xy.z0 = map[x][y];
	xy.z1 = map[x + 1][y];
	xy.y0 = ((-map[x][y]) + (x * scale + OFFSETYY));
	xy.x0 = ((-map[x][y]) + (y * scale + OFFSETXX));
	xy.y1 = ((-map[x + 1][y]) + (x * scale + scale + OFFSETYY));
	xy.x1 = ((-map[x + 1][y]) + (y * scale + OFFSETXX));
	return (xy);
}

int	*plot_map_horizontal(int *dump, int **map, int size_line, t_img img)
{
	int		x;
	int		y;
	t_coord	coord;

	coord.z0 = 0;
	coord.z1 = 0;
	x = 0;
	y = 0;
	while (x < img.lines - 1)
	{
		while (y < img.line_len - 1)
		{
			coord = get_coord_horiz(coord, map, x, y, img.scale);
			coord = iso(coord, img);
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
	int		x;
	int		y;
	t_coord	coord;

	coord.z0 = 0;
	coord.z1 = 0;
	x = 0;
	y = 0;
	while (x < img.lines - 2)
	{
		while (y < img.line_len)
		{
			coord = get_coord_vert(coord, map, x, y, img.scale);
			coord = iso(coord, img);
			coord = bresenham(coord, img);
			y++;
		}
		x++;
		y = 0;
	}
	return (dump);
}
