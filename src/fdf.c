/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:41:21 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/19 17:34:23 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_img	img;

	if (!validation(argc, argv))
		return (1);
	init_image_data(&img, argv);
	plot_map_horizontal(img);
	plot_map_vertical(img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);
	print_commands(&img);
	mlx_hook(img.win_ptr, 2, 1L << 0, &screen_controller, &img);
	mlx_loop(img.mlx_ptr);
	return (0);
}
