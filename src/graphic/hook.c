/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:04:36 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/17 18:29:07 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rot_player(t_info *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		info->player->player_angle += 0.1;
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		info->player->player_angle -= 0.1;
	printf ("angle: %f\n", info->player->player_angle);
}

void	move_player(t_info *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
	{
		info->player->player_x += cos(info->player->player_angle) * -1;
		info->player->player_y += sin(info->player->player_angle) * -1;
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
	{
		info->player->player_x += cos(info->player->player_angle) * 1;
		info->player->player_y += sin(info->player->player_angle) * 1;
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
	{
		info->player->player_x -= cos(info->player->player_angle + M_PI_2) * -1;
		info->player->player_y -= sin(info->player->player_angle + M_PI_2) * -1;
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
	{
		info->player->player_x += cos(info->player->player_angle + M_PI_2) * 1;
		info->player->player_y += sin(info->player->player_angle + M_PI_2) * 1;
	}
	printf ("x: %d, y: %d\n", info->player->player_x, info->player->player_y);
}

void ft_hook(void* param)
{
	t_info *info;

	info = (t_info *)param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		rot_player(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		rot_player(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W)
		|| mlx_is_key_down(info->mlx, MLX_KEY_S)
		|| mlx_is_key_down(info->mlx, MLX_KEY_A)
		|| mlx_is_key_down(info->mlx, MLX_KEY_D))
		move_player(info);
}
