/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:41:21 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 11:53:33 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	set_scale(t_img *img, int **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (WIDTH / img->line_len < 30)
		img->scale = WIDTH / img->line_len / 2;
	else
		img->scale = 30;
	printf("scale: %d\n", img->scale);
	img->max_height = 0;
	while (i < img->lines - 1)
	{
		while (j < img->line_len - 1)
		{
			if (map[i][j] > img->max_height)
				img->max_height = map[i][j];
			++j;
		}
		j = 0;
		i++;
	}
}

static void	init_image_data(t_img *img)
{
	img->offsetx = 200;
	img->offsety = 400;
	img->cos1 = 1.0;
	img->sin1 = 2.0;
	set_scale(img, img->map);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->win_ptr = mlx_new_window(img->mlx_ptr, WIDTH, HEIGHT, "hello world!");
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
}

int	main(int argc, char **argv)
{
	t_img	img;

	setbuf(stdout, NULL);
	img.mlx_ptr = mlx_init();
	img.map = parse_map(argv[1], &img);
	init_image_data(&img);
	plot_map_horizontal(img.dump, img.map, img.size_line, img);
	plot_map_vertical(img.dump, img.map, img.size_line, img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);
	mlx_hook(img.win_ptr, 2, 1L << 0, &screen_controller, &img);
	mlx_loop(img.mlx_ptr);
	return (0);
}
