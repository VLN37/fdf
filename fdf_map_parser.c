/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 00:37:53 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/17 15:30:35 by jofelipe         ###   ########.fr       */
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

//line[i] = 0;
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
	return (line);
}

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

// map[i] = (int *)malloc(sizeof(int) *( img->line_len + 1));
// ft_bzero((void *)map[i++], (img->line_len) * sizeof(int));
int	**parse_map(char *file, t_img *img)
{
	int		i;
	int		fd;
	char	*str;
	int		**map;

	i = 0;
	str = "init";
	img->lines = file_line_count(file);
	img->line_len = file_line_size(file);
	map = (int **)malloc(sizeof(int *) * (img->lines));
	fd = open(file, O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			map[i] = (int *)malloc(sizeof(int) * (img->line_len));
			string_to_intarr(str, map[i]);
			free (str);
			i++;
		}
	}
	set_scale(img, map);
	map[i] = NULL;
	return (map);
}
