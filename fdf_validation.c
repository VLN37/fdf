/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:03:55 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/19 15:10:08 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	validation(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_putstr_fd("No map specified.\nExpected usage: ./fdf (map)\n Valid \
		maps: 42.fdf 10-70.fdf 20-60.fdf 50-4.fdf 100-6.fdf basictest.fdf elem.\
		fdf elem2.fdf mars.fdf pentenegpos.fdf plat.fdf pnp_flat.fdf pylone.fdf\
		 pyra.fdf", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map does not exist.\nExpected usage: ./fdf (map)\n Valid \
		maps: 42.fdf 10-70.fdf 20-60.fdf 50-4.fdf 100-6.fdf basictest.fdf elem.\
		fdf elem2.fdf mars.fdf pentenegpos.fdf plat.fdf pnp_flat.fdf pylone.fdf\
		 pyra.fdf\n", 2);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
