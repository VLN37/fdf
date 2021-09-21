/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:33:57 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/20 22:39:59 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static void	get_height(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	img->max_height = 0;
	img->min_height = 0;
	while (i < img->lines - 1)
	{
		while (j < img->line_len - 1)
		{
			if (img->map[i][j] > img->max_height)
				img->max_height = img->map[i][j];
			if (img->map[i][j] < img->min_height)
				img->min_height = img->map[i][j];
			++j;
		}
		j = 0;
		i++;
	}
}

static int	key_j(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (img->map[++i])
	{
		j = -1;
		while (++j < img->line_len - 1)
		{
			if (img->map[i][j] < 3 && img->map[i][j] > 0)
				img->map[i][j] = -1;
			if (img->map[i][j])
				img->map[i][j] -= 3;
		}
	}
	get_height(img);
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	print_commands(img);
	return (0);
}

static int	key_k(t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (img->map[++i])
	{
		j = -1;
		while (++j < img->line_len - 1)
		{
			if (img->map[i][j] > -3 && img->map[i][j] < 0)
				img->map[i][j] = 1;
			if (img->map[i][j])
				img->map[i][j] += 3;
		}
	}
	get_height(img);
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(*img);
	plot_map_vertical(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	print_commands(img);
	return (0);
}

int	keys_height(int key, t_img *img)
{
	if (key == KEY_J)
		key_j(img);
	if (key == KEY_K)
		key_k(img);
	return (0);
}
