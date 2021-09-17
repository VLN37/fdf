/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:41:21 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/16 20:32:56 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

//remind to check whether i have to free dump and image pointers
int	key_press(int keycode, t_img *img)
{
	void	*tmp1;
	int		*tmp2;

	printf("%d\n", keycode);
	//tmp1 = img->win_img;
	//tmp2 = img->dump;
	img->offsetx += 10;
	mlx_destroy_image(img->mlx_ptr, img->win_img);
	img->win_img = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->dump = (int *)mlx_get_data_addr(img->win_img, \
	&img->bbp, &img->size_line, &img->end);
	plot_map_horizontal(img->dump, img->map, img->size_line, *img);
	plot_map_vertical(img->dump, img->map, img->size_line, *img);
	//mlx_clear_window(img->mlx_ptr, img->win_ptr);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->win_img, 0, 0);
	//free (tmp1);
	//free (tmp2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_img	img;

	img.offsetx = 200;
	img.offsety = 400;
	setbuf(stdout, NULL);
	img.mlx_ptr = mlx_init();
	if (!img.mlx_ptr)
		return (1);

	img.map = parse_map(argv[1], &img);
	img.cos1 = 1.0;
	img.sin1 = 2.0;
	img.win_img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.dump = (int *)mlx_get_data_addr(img.win_img, \
	&img.bbp, &img.size_line, &img.end);

	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "hello world!");

	plot_map_horizontal(img.dump, img.map, img.size_line, img);
	plot_map_vertical(img.dump, img.map, img.size_line, img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);

	mlx_hook(img.win_ptr, 2, 1L << 0, &screen_controller, &img);
	mlx_loop(img.mlx_ptr);
}
