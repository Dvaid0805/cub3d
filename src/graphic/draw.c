/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:27:11 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/23 17:31:40 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_floor_ceilings(t_info *info)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (col < SCR_W)
	{
		row = 0;
		while (row < SCR_H)
		{
			if (row < SCR_H / 2)
				mlx_put_pixel(info->img, col, row, info->c_color);
			else if (row > SCR_H)
				mlx_put_pixel(info->img, col, row, info->f_color);
			else
				mlx_put_pixel(info->img, col, row, 0x000000);
			row++;
		}
		col++;
	}
}
