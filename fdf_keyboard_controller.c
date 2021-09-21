/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_controller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:46:29 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/20 22:15:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	print_commands(t_img *img)
{

	mlx_string_put(img->mlx_ptr, img->win_ptr, 0, 10, 0xFFFFFF, \
	"Commands:");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 0, 20, 0xFFFFFF, \
	"arrows  - location");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 0, 30, 0xFFFFFF, \
	"w s     - zoom");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 0, 40, 0xFFFFFF, \
	"a d     - stretch horizontally");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 0, 50, 0xFFFFFF, \
	"q e     - stretch vertically");
	mlx_string_put(img->mlx_ptr, img->win_ptr, 0, 60, 0xFFFFFF, \
	"k j     - max height");
}

static int	key_q(t_img *img)
{
	if (img->sin1 > -0.2 && img->sin1 < 0.0)
		img->sin1 = 0.1;
	if (img->sin1 > 15.0)
		img->sin1 = -15.0;
	else if (img ->sin1 > 5.0 || img->sin1 < -5.0)
		img->sin1 += 0.5;
	else
		img->sin1 += 0.1;
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

static int	key_e(t_img *img)
{
	if (img->sin1 < 0.2 && img->sin1 > 0.0)
		img->sin1 = -0.1;
	if (img->sin1 < -15.0)
		img->sin1 = 15.0;
	else if (img->sin1 < -5.0 || img->sin1 > 5.0)
		img->sin1 -= 1.0;
	else
		img->sin1 -= 0.1;
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

static void	cleanup(t_img *img)
{
	int	i;

	i = 0;
	while (img->map[i])
		free(img->map[i++]);
	free(img->map);
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	exit(0);
}

int	screen_controller(int key, t_img *img)
{
	printf("%d\n", key);
	if (key == KEY_UP || key == KEY_RIGHT || key == KEY_LEFT || key == KEY_DOWN)
		keys_arrow(key, img);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		keys_wasd(key, img);
	if (key == KEY_K || key == KEY_J)
		fdf_keys_height(key, img);
	if (key == KEY_Q)
		key_q(img);
	if (key == KEY_E)
		key_e(img);
	if (key == KEY_ESC)
		cleanup(img);
	return (0);
}
