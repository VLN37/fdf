/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys_arrow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:01:25 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 15:46:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	key_up(t_img *img)
{
	img->offsety -= 20;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

static int	key_down(t_img *img)
{
	img->offsety += 20;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

static int	key_right(t_img *img)
{
	img->offsetx += 20;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

static int	key_left(t_img *img)
{
	img->offsetx -= 20;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

int	keys_arrow(int key, t_img *img)
{
	if (key == KEY_UP)
		key_up(img);
	else if (key == KEY_DOWN)
		key_down(img);
	else if (key == KEY_LEFT)
		key_left (img);
	else if (key == KEY_RIGHT)
		key_right(img);
	return (0);
}
