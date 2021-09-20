/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:33:57 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/20 20:27:09 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static int	key_j(t_img *img)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (img->map[i])
	{
		while (j < img->line_len - 1)
		{
			if (img->map[i][j] == 1)
				img->map[i][j] = -1;
			if (img->map[i][j])
				img->map[i][j] -= 1;
			j++;
		}
		i++;
		j = 0;
	}
	set_scale(img, img->map);
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

static int	key_k(t_img *img)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (img->map[i])
	{
		while (j < img->line_len - 1)
		{
			if (img->map[i][j] == -1)
				img->map[i][j] = 1;
			if (img->map[i][j])
				img->map[i][j] += 1;
			j++;
		}
		i++;
		j = 0;
	}
	set_scale(img, img->map);
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	return (0);
}

int	fdf_keys_height(int key, t_img *img)
{
	if (key == KEY_J)
		key_j(img);
	if (key == KEY_K)
		key_k(img);
	return (0);
}
