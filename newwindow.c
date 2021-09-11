/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newwindow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:29:24 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/11 01:07:32 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "mlx.h"

int	*put_horizontal_line(int *img, int width, int height, int size_line)
{
	int	col;
	int	line;

	col = OFFSET;
	line = OFFSET;
	while (line <= height - OFFSET)
	{
		while (col <= width - OFFSET)
		{
			img[col + (line * size_line / 4)] = 0xFFFFFF;
			col++;
		}
		line += INCREMENT;
		col = OFFSET;
	}
	return (img);
}

int	*put_vertical_line(int *img, int width, int height, int size_line)
{
	int	col;
	int	line;

	col = OFFSET;
	line = OFFSET;
	while (col <= width - OFFSET)
	{
		while (line <= height - OFFSET)
		{
			img[col + (line * (size_line / 4))] = 0xFFFFFF;
			line++;
		}
		col += INCREMENT;
		line = OFFSET;
	}
	return (img);
}

int	main(void)
{
	t_img	data;
	int		*dump;
	int		y;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	dump = (int *)mlx_get_data_addr(data.win_img, \
	&data.bbp, &data.size_line, &data.end);
	dump = put_horizontal_line(dump, WIDTH, HEIGHT, data.size_line);
	dump = put_vertical_line(dump, WIDTH, HEIGHT, data.size_line);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "hello world!");
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.win_img, 0, 0);
	mlx_loop(data.mlx_ptr);
}
	// y = 32000;
	// while (y < 32800)
	// {
	// 	dump[y] = 0xFFFFFF;
	// 	y++;
	// }
	// y = 64000;
	// while (y < 64800)
	// {
	// 	dump[y] = 0xFFFFFF;
	// 	y++;
	// }
	// y = 96000;
	// while (y < 96800)
	// {
	// 	dump[y] = 0xFFFFFF;
	// 	y++;
	// }
