/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:47:37 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 13:54:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static int	color_up(t_coord *xy, t_img *img)
{
	int	color;

	color = 0xFFFDFD;
	xy->colorfactor = 255.00 / (float)xy->pixellen;
	if (xy->z0 > 0)
	{
		color -= 0x000101 * xy->heightfactor * xy->z0;
		xy->colorfactor = 255.00 / (float)xy->pixellen / \
		((float)xy->z1 -((float) xy->z0 + 0.01));
	}
	return (color);
}

static int	color_down(t_coord *xy, t_img *img)
{
	int	color;

	color = 0xFF0101;
	xy->colorfactor = 255.00 / (float)xy->pixellen;
	if (xy->z0 < img->max_height)
	{
		color -= 0x000101 * xy->heightfactor * xy->z0;
		xy->colorfactor = 255.00 / ((float)xy->pixellen + 0.01) / \
		(((float)xy->z0 + 0.01) / ((float)xy->z1 + 0.01));
	}
	return (color);
}

int	get_color(t_coord *xy, t_img *img)
{
	int	color;

	if (xy->z0 < xy->z1)
		color = color_up(xy, img);
	else if (xy->z0 > xy->z1)
		color = color_down(xy, img);
	else
	{
		color = 0xffFDFD;
		if (xy->z0 > 0)
			color -= 0x000101 * xy->heightfactor * xy->z0;
	}
	return (color);
}
