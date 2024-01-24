/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:04:36 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/24 16:30:54 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rot_player(t_info *info, int angle)
{
	double	new_angle;

	new_angle = info->player->player_angle + (0.1 * angle);
	if (new_angle > 2 * M_PI)
		new_angle -= 2 * M_PI;
	else if (new_angle < 0)
		new_angle += 2 * M_PI;
	info->player->player_angle = new_angle;
}

void ft_hook(void* param)
{
	t_info *info;

	info = (t_info *)param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		rot_player(info, 1);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		rot_player(info, -1);
	/* if (mlx_is_key_down(info->mlx, MLX_KEY_W)
		|| mlx_is_key_down(info->mlx, MLX_KEY_S)
		|| mlx_is_key_down(info->mlx, MLX_KEY_A)
		|| mlx_is_key_down(info->mlx, MLX_KEY_D))
		move_player(info); */
	draw(info);
}
