/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:03:55 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 16:30:44 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	validation(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_putstr_fd("Map not specified.", 2);
		ft_putstr_fd("Expected usage: ./fdf (map_path)\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map does not exist.", 2);
		ft_putstr_fd("Expected usage: ./fdf (map_path)\n", 2);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
