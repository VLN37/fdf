/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_controller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:46:29 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 13:24:35 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

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
	if (key == KEY_UP || key == KEY_RIGHT || key == KEY_LEFT || key == KEY_DOWN)
		keys_arrow(key, img);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		keys_wasd(key, img);
	if (key == KEY_ESC)
		cleanup(img);
	return (0);
}
