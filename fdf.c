/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:41:21 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 13:39:12 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_img	img;

	setbuf(stdout, NULL);
	if (!validation(argc, argv))
		return (1);
	img.mlx_ptr = mlx_init();
	img.map = parse_map(argv[1], &img);
	init_image_data(&img);
	plot_map_horizontal(img);
	plot_map_vertical(img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);
	mlx_hook(img.win_ptr, 2, 1L << 0, &screen_controller, &img);
	mlx_loop(img.mlx_ptr);
	return (0);
}
