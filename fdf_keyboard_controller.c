/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_controller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:46:29 by jofelipe          #+#    #+#             */
/*   Updated: 2021/09/16 15:26:22 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	screen_controller(int key, t_img *img)
{
	if (key == KEY_UP || key == KEY_RIGHT || key == KEY_LEFT || key == KEY_DOWN)
		keys_arrow(key, img);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		keys_wasd(key, img);
}
