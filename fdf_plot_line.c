/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 05:53:18 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/17 10:16:01 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static int	gradient(int color, t_coord *xy, t_img img)
{
	int	up;
	int	down;

	up = 0x000101;
	if (xy->z0 == 0 && xy->z1 == 0)
		return (0xFFFFFF);
	if (xy->z0 == img.max_height && xy->z1 == img.max_height)
		return (0x990099);
	// if (xy->z0 == xy->z1)
	// 	return (color);
	if (xy->z0 < xy->z1)
	{
		color -= up * xy->colorfactor * xy->iteration;
		//* heightfactor ?
		if (color < 0xff1a1a)
			return(0xff1a1a);
	}
	else if(xy->z0 > xy->z1)
	{
		color += up * xy->colorfactor * xy->iteration;
		//* heightfactor ?
		if (color > 0xFFFFFF)
			return(0xFFFFFF);
	}
	xy->iteration += 2;
	//xy->lastcolor = color;
	return (color);
}
//fator da altura e multiplicar o inicio por essa diferença
// 1 - 255 / altura maxima
// > 0


static t_coord	init_bresenham(t_coord xy, t_img img)
{
	xy.iteration = 0;
	xy.colorfactor = 50 / img.max_height;
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

// t_coord	bresenham(t_coord xy, t_img img)
// {
// 	xy = init_bresenham(xy, img);
// 	int	color;
// 	int	heightfactor;

// 	heightfactor = 1;
// 	if (xy.z0 < xy.z1 && xy.z0 == 0)
// 		color = 0xffe6e6;
// 	else if (xy.z0 > xy.z1 && xy.z1 == 0)
// 		color = 0xFF1a1a;
// 	// if (xy.z0 > 0 && xy.z1 > xy.z0 || xy.z0 < img.max_height && xy.z0 > xy.z1)
// 	// 	heightfactor = (255 * xy.z0) / img.max_height;
// 	// color += heightfactor
// 	printf("%d\n", bresenham_len(xy, img));
// 	while (1)
// 	{
// 		if (xy.x0 == xy.x1 && xy.y0 == xy.y1)
// 			break ;
// 		xy.e2 = 2 * xy.err;
// 		if (xy.e2 >= xy.dy)
// 		{
// 			xy.err += xy.dy;
// 			if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT )
// 				img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] = gradient(color, &xy, img);
// 			xy.x0 += xy.sx;
// 		}
// 		if (xy.e2 <= xy.dx)
// 		{
// 			xy.err += xy.dx;
// 			if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT )
// 					img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] = gradient(color, &xy, img);
// 			xy.y0 += xy.sy;
// 		}
// 	}
// 	// xy.lastcolor = color;
// 	return (xy);
// }

t_coord	bresenham(t_coord xy, t_img img)
{
	xy = init_bresenham(xy, img);
	int	color;
	int	heightfactor;

	heightfactor = 1;
	if (xy.z0 < xy.z1 && xy.z0 == 0)
		color = 0xffFDFD;
	else if (xy.z0 > xy.z1 && xy.z1 == 0)
		color = 0xFF0101;
	// if (xy.z0 > 0 && xy.z1 > xy.z0 || xy.z0 < img.max_height && xy.z0 > xy.z1)
	// 	heightfactor = (255 * xy.z0) / img.max_height;
	// color += heightfactor

	printf("%d\n", bresenham_len(xy, img));
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
		if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT )
			img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] = gradient(color, &xy, img);
	}
	// xy.lastcolor = color;
	return (xy);
}
