/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:48:04 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/16 18:18:31 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 

void	draw_col(t_info *info, t_ray *ray, int i)
{
	int		j;
	int		color;
	double	step;
	double	tex_pos;
	double	tex_y;

	j = 0;
	step = 1.0 * TEX_H / ray->height;
	tex_pos = (ray->start - (SCR_H / 2) + (ray->height / 2)) * step;
	while (j < SCR_H)
	{
		if (j < ray->start)
			color = info->c_color;
		else if (j > ray->start + ray->height)
			color = info->f_color;
		else
		{
			tex_y = (int)tex_pos & (TEX_H - 1);
			tex_pos += step;
			color = info->texture[ray.texture][TEX_H * tex_y + ray.tex_x];
		}
		info->g_img->data[j * SCR_W + i] = color;
		j++;
	}
}
 */