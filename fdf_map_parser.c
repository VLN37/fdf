/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 00:37:53 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/14 08:02:19 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	file_line_size(char *file)
{
	int		i;
	int		j;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	// close(fd);
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

static int	file_line_count(char *file)
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

static int	*string_to_intarr(char *str, int *line)
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
	//line[i] = 0;
	return (line);
}

void set_scale(t_data *map_data, int **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (WIDTH / map_data->line_len < 30)
		map_data->scale = WIDTH / map_data->line_len / 2;
	else
		map_data->scale = 30;
	printf("%d\n", map_data->scale);
	map_data->max_height = 0;
	while (i < map_data->lines - 1)
	{
		while(j < map_data->line_len - 1)
		{
			if (map[i][j] > map_data->max_height)
				map_data->max_height = map[i][j];
			++j;
		}
		j = 0;
		i++;
	}
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

	map = (int **)malloc(sizeof(int *) * (map_data->lines));
	fd = open(file, O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			map[i] = (int *)malloc(sizeof(int) *( map_data->line_len));
			string_to_intarr(str, map[i]);
			free (str);
			i++;
		}
	}
	set_scale(map_data, map);
	// map[i] = (int *)malloc(sizeof(int) *( map_data->line_len + 1));
	// ft_bzero((void *)map[i++], (map_data->line_len) * sizeof(int));
	map[i] = NULL;
	return (map);
}

