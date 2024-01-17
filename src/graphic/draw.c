/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:27:11 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/17 12:23:53 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_floor_ceilings(t_info *info)
{
	int	row;
	int	col;
	double scale;
	/* int dist = 600; */

	row = 0;
	col = 0;
	while (col < SCR_W)
	{
		row = 0;
		scale = 1.0 - (double)col / SCR_W;
		while (row < SCR_H - 1)
		{
			if (row < SCR_H / 2 - scale / 2)
				mlx_put_pixel(info->img, col, row, info->c_color);
			else if (row > SCR_H / 2 + scale / 2)
				mlx_put_pixel(info->img, col, row, info->f_color);
			else if (row > SCR_H / 2 - scale / 2 && row < SCR_H / 2 + scale / 2)
				mlx_put_pixel(info->img, col, row, 0X00FF00FF);
			row++;
		}
		col++;
	}
}
