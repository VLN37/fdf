/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:25:00 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/14 03:39:34 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		**map;
	t_data	map_data;

	if (argc != 2)
		printf("expected usage: ./a.out (filename)\n");
	map = parse_map(argv[1], &map_data);

	int	i = 0;
	int	j = 0;
	while (map[i])
	{
		while(j < map_data.line_len + 1)
			printf("%3d", map[i][j++]);
		i++;
		j = 0;
		printf("\n");
	}
	while (i < map_data.lines)
		free(map[i++]);
	free(map);
}
