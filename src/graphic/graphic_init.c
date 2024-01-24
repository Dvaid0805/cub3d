/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:07:09 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/24 12:15:18 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void testhook(mlx_key_data_t keydata, void* param)
{
	t_info *info;

	info = (t_info *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(info->mlx);
}

void graphic_init(t_info *info)
{
	info->mlx = mlx_init(SCR_W, SCR_H, "cub3D", false);
	if (!info->mlx)
		unplanned_exit(info, E_MLX);
	info->img = mlx_new_image(info->mlx, SCR_W, SCR_H);
	if (!info->img)
		unplanned_exit(info, E_MLX);
	mlx_image_to_window(info->mlx, info->img, 0, 0);
	draw(info);
	/* mlx_loop_hook(info->mlx, ft_hook, info); */
	mlx_key_hook(info->mlx, testhook, info);
	mlx_loop(info->mlx);
}
