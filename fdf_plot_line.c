/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 05:53:18 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/20 21:37:29 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

// if (color < 0xff1a1a)
// 	return(0xff1a1a);
// if (color > 0xFFFFFF)
// 	return(0xFFFFFF);
static int	gradient(int color, t_coord *xy, t_img img)
{
	int	up;

	up = 0x000101;
	if (xy->z0 == 0 && xy->z1 == 0)
		return (0xFFFFFF);
	if (xy->z0 == img.max_height && xy->z1 == img.max_height)
		return (0x990099);
	if (xy->z0 == img.min_height && xy->z1 == img.min_height)
		return (0x990099);
	if (xy->z0 == xy->z1)
		return (color);
	if (xy->z0 < xy->z1)
		color -= up * xy->colorfactor * xy->iteration;
	else if (xy->z0 > xy->z1)
		color += up * xy->colorfactor * xy->iteration;
	xy->iteration += 1;
	return (color);
}

static t_coord	init_bresenham(t_coord xy, t_img img)
{
	xy.iteration = 0;
	xy.x0 += img.offsetx;
	xy.x1 += img.offsetx;
	xy.y1 += img.offsety;
	xy.y0 += img.offsety;
	xy.dx = abs(xy.x1 - xy.x0);
	xy.dy = -abs(xy.y1 - xy.y0);
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

int	bresenham_len(t_coord xy, t_img img)
{
	int	i;

	i = 0;
	while (1)
	{
		if (xy.x0 == xy.x1 && xy.y0 == xy.y1)
			break ;
		xy.e2 = 2 * xy.err;
		if (xy.e2 >= xy.dy)
		{
			xy.err += xy.dy;
			xy.x0 += xy.sx;
		}
		if (xy.e2 <= xy.dx)
		{
			xy.err += xy.dx;
			xy.y0 += xy.sy;
		}
		i++;
	}
	return (i);
}

// printf("pixellen %d, colorfactor %f, heightfactor %f\n"
// , xy.pixellen, xy.colorfactor, xy.heightfactor);
void	bresenham(t_coord xy, t_img img)
{
	int	color;

	xy = init_bresenham(xy, img);
	xy.heightfactor = 255.00 / (float)img.max_height;
	xy.pixellen = bresenham_len(xy, img);
	color = get_color(&xy, &img);
	while (1)
	{
		if (xy.x0 == xy.x1 && xy.y0 == xy.y1)
			break ;
		xy.e2 = 2 * xy.err;
		if (xy.e2 >= xy.dy)
		{
			xy.err += xy.dy;
			xy.x0 += xy.sx;
		}
		if (xy.e2 <= xy.dx)
		{
			xy.err += xy.dx;
			xy.y0 += xy.sy;
		}
		if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT)
			img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] \
			= gradient(color, &xy, img);
	}
}
