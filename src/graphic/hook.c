/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:04:36 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/24 20:28:48 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		rot_player(info, 1);
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		rot_player(info, -1);
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		move_up(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		move_down(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		move_left(info);
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		move_right(info);
	draw(info);
}
