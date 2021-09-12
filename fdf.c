/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 05:41:21 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/12 08:01:40 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	iso(int carx, int cary, int mod)
{
	int	isox;
	int	isoy;

	isox = carx + cary;
	isoy = cary - carx / 2.0;

	carx = (isox - isoy) / 1.5;
	cary = isox / 3.0 + isoy / 1.5;
	if (mod == 1)
		return (isoy);
	return (isox);
}

int	main(int argc, char **argv)
{
	int		**map;
	int		*dump;
	int		coord[4];
	t_data	map_data;
	t_img	img;

	if (argc != 2)
	{
		write(2, "expected usage: ./a.out (mapfile)\n", 35);
		return (1);
	}
	map = parse_map(argv[1], &map_data);
	img.mlx_ptr = mlx_init();
	if(!img.mlx_ptr)
		return (1);
	img.win_img = mlx_new_image(img.mlx_ptr, WIDTH, HEIGHT);
	img.dump = (int *)mlx_get_data_addr(img.win_img, \
	&img.bbp, &img.size_line, &img.end);

	coord[0] = 100;
	coord[1] = 100;
	coord[2] = 400;
	coord[3] = 1;


// 	img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "hello world!");
// 	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.win_img, 0, 0);
}
