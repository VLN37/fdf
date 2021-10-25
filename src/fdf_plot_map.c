/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 22:36:05 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/20 14:55:24 by jofelipe         ###   ########.fr       */
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

static t_coord	get_coord_horiz(t_coord xy, t_img img, int x, int y)
{
	xy.z0 = img.map[x][y];
	xy.z1 = img.map[x][y + 1];
	xy.y0 = ((-img.map[x][y]) + (x * img.scale + OFFSETYY));
	xy.x0 = ((-img.map[x][y]) + (y * img.scale + OFFSETXX));
	xy.y1 = ((-img.map[x][y + 1]) + (x * img.scale + OFFSETYY));
	xy.x1 = ((-img.map[x][y + 1]) + (y * img.scale + img.scale + OFFSETXX));
	return (xy);
}

static t_coord	get_coord_vert(t_coord xy, t_img img, int x, int y)
{
	xy.z0 = img.map[x][y];
	xy.z1 = img.map[x + 1][y];
	xy.y0 = ((-img.map[x][y]) + (x * img.scale + OFFSETYY));
	xy.x0 = ((-img.map[x][y]) + (y * img.scale + OFFSETXX));
	xy.y1 = ((-img.map[x + 1][y]) + (x * img.scale + img.scale + OFFSETYY));
	xy.x1 = ((-img.map[x + 1][y]) + (y * img.scale + OFFSETXX));
	return (xy);
}

int	*plot_map_horizontal(t_img img)
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
			coord = get_coord_horiz(coord, img, x, y);
			coord = iso(coord, img);
			bresenham(coord, img);
			y++;
		}
		x++;
		y = 0;
	}
	return (img.dump);
}

int	*plot_map_vertical(t_img img)
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
			coord = get_coord_vert(coord, img, x, y);
			coord = iso(coord, img);
			bresenham(coord, img);
			y++;
		}
		x++;
		y = 0;
	}
	return (img.dump);
}
