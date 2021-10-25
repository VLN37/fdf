/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parser_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:25:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/10/23 09:59:03 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		**map;
	int		j;
	int		i;
	t_img	img;

	if (argc != 2)
		ftex_minprintf("expected usage: ./a.out (filename)\n");
	map = parse_map(argv[1], &img);
	i = 0;
	j = 0;
	while (map[i])
	{
		while (j < img.line_len + 1)
			ftex_minprintf("%3d", map[i][j++]);
		i++;
		j = 0;
		ftex_minprintf("\n");
	}
	while (i < img.lines)
		free(map[i++]);
	free(map);
}
