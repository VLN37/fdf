/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys_wasd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:24:06 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/16 15:36:58 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static int	key_w(t_img *img)
{
	img->scale += 2;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(img->dump, img->map, img->size_line, *img);
	plot_map_vertical(img->dump, img->map, img->size_line, *img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

static int	key_a(t_img *img)
{
	img->sin1 += 0.1;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(img->dump, img->map, img->size_line, *img);
	plot_map_vertical(img->dump, img->map, img->size_line, *img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

static int	key_s(t_img *img)
{
	img->scale -= 2;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(img->dump, img->map, img->size_line, *img);
	plot_map_vertical(img->dump, img->map, img->size_line, *img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

static int	key_d(t_img *img)
{
	img->sin1 -= 0.1;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(img->dump, img->map, img->size_line, *img);
	plot_map_vertical(img->dump, img->map, img->size_line, *img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}


int	keys_wasd(int key, t_img *img)
{
	if (key == KEY_W)
		key_w(img);
	if (key == KEY_A)
		key_a(img);
	if (key == KEY_S)
		key_s(img);
	if (key == KEY_D)
		key_d(img);
}
