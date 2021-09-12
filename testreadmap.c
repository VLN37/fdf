/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testreadmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 00:37:53 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/12 05:21:08 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	file_line_size(char *file)
{
	int		i;
	int		j;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (ft_isdigit(str[j]) || str[j] == '-')
		{
			i++;
			while (ft_isdigit(str[j]) || str[j] == '-')
				j++;
		}
		if (str[j])
			j++;
	}
	while (str)
	{
		free (str);
		str = get_next_line(fd);
	}
	close(fd);
	printf("line len %d\n", i);
	return (i);
}

int	file_line_count(char *file)
{
	int		fd;
	char	*str;
	int		res;

	res = 0;
	str = "init";
	fd = open(file, O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		res++;
		free(str);
	}
	printf("line count %d\n", res);
	close(fd);
	return (res);
}

int	*string_to_intarr(char *str, int *line)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str) || *str == '-')
			line[i++] = ft_atoi(str);
		while (ft_isdigit(*str) || *str == '-')
			str++;
		if (*str)
			str++;
	}
	for (int i = 0; i < 19; i++)
		printf("%3d", line[i]);
	printf("\n");
	return (line);
}

int **parse_map(char *file, t_data *map_data)
{
	int		i;
	int		fd;
	char	*str;
	int		**map;

	i = 0;
	str = "init";
	map_data->lines = file_line_count(file);
	map_data->line_len = file_line_size(file);
	map = (int **)malloc(sizeof(int *) * map_data->lines);
	fd = open(file, O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			map[i] = (int *)malloc(sizeof(int) * map_data->line_len);
			string_to_intarr(str, map[i]);
			free (str);
			i++;
		}
	}
	map[i] = NULL;
	return (map);
}

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
	while (i < map_data.lines)
		free(map[i++]);
	free(map);
}
