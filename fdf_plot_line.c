/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 05:53:18 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/16 15:12:00 by jofelipe         ###   ########.fr       */
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
	if (xy->z0 == xy->z1)
		return (color);
	if (xy->z0 < xy->z1)
	{
		color -= up * xy->colorfactor * xy->iteration;
		if (color < 0xff1a1a)
			return(0xff1a1a);
	}
	else if(xy->z0 > xy->z1)
	{
		color += up * xy->colorfactor * xy->iteration;
		if (color > 0xFFFFFF)
			return(0xFFFFFF);
	}
	xy->iteration += 2;
	//xy->lastcolor = color;
	return (color);
}

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
	xy = init_bresenham(xy, img);
	int	color;

	// if ((xy.z0 < xy.z1 && xy.z0 > 0)
	// || (xy.z0 > xy.z1 && xy.z0 < img.max_height))
	// 	color = xy.lastcolor;
	// if (xy.z0 == xy.z1)
	// 	color = 0xFF1a1a;
	if (xy.z0 < xy.z1 && xy.z0 == 0)
		color = 0xffe6e6;
	else if (xy.z0 > xy.z1 && xy.z1 == 0)
		color = 0xFF1a1a;
	// else
	// 	color = xy.lastcolor;

	while (1)
	{
		if (xy.x0 == xy.x1 && xy.y0 == xy.y1)
			break ;
		xy.e2 = 2 * xy.err;
		if (xy.e2 >= xy.dy)
		{
			xy.err += xy.dy;
			if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT )
				img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] = gradient(color, &xy, img);
			xy.x0 += xy.sx;
		}
		if (xy.e2 <= xy.dx)
		{
			xy.err += xy.dx;
			if (xy.x0 < WIDTH && xy.x0 > 0 && xy.y0 > 0 && xy.y0 < HEIGHT )
				img.dump[xy.x0 + (xy.y0 * img.size_line / 4)] = gradient(color, &xy, img);
			xy.y0 += xy.sy;
		}
	}
	// xy.lastcolor = color;
	return (xy);
}



// static int get_initial_color(int maxh, int currh, t_coord *xy, t_img img)
// {
// 	if (xy->z0 == 0 && xy->z1 == 0)
// 		return (0xFFFFFF);
// 	else if (xy->z0 == img.max_height && xy->z1 == img.max_height)
// 		return(0x990099);
// 	else if (currh * 1 < maxh)
// 		return(0xffe6e6);
// 	else if (currh * 2 < maxh)
// 		return(0xffcccc);
// 	else if (currh * 3 < maxh)
// 		return(0xffb3b3);
// 	else if (currh * 4 < maxh)
// 		return(0xff9999);
// 	else if (currh * 5 < maxh)
// 		return(0xff8080);
// 	else if (currh * 6 < maxh)
// 		return(0xff6666);
// 	else if (currh * 7 < maxh)
// 		return(0xff4d4d);
// 	else if (currh * 8 < maxh)
// 		return(0xff3333);
// 	else if (currh * 9 < maxh)
// 		return(0xff1a1a);
// }
