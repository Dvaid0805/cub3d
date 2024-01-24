/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:28:00 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/24 22:39:44 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->player_x + (MOVE_SPEED * cos(info->player->player_angle));
	new_y = info->player->player_y + (MOVE_SPEED * sin(info->player->player_angle));
	if (!is_wall(new_x, new_y, info))
	{
		info->player->player_x = new_x;
		info->player->player_y = new_y;
	}
}

void	move_down(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->player_x - (MOVE_SPEED * cos(info->player->player_angle));
	new_y = info->player->player_y - (MOVE_SPEED * sin(info->player->player_angle));
	if (!is_wall(new_x, new_y, info))
	{
		info->player->player_x = new_x;
		info->player->player_y = new_y;
	}
}

void	move_right(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->player_x + (MOVE_SPEED * cos(info->player->player_angle - M_PI_2));
	new_y = info->player->player_y + (MOVE_SPEED * sin(info->player->player_angle - M_PI_2));
	if (!is_wall(new_x, new_y, info))
	{
		info->player->player_x = new_x;
		info->player->player_y = new_y;
	}
}

void	move_left(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->player_x + (MOVE_SPEED * cos(info->player->player_angle + M_PI_2));
	new_y = info->player->player_y + (MOVE_SPEED * sin(info->player->player_angle + M_PI_2));
	if (!is_wall(new_x, new_y, info))
	{
		info->player->player_x = new_x;
		info->player->player_y = new_y;
	}
}
