/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:10:17 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/23 23:15:26 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	calc_collision_y(t_info *info)
{
	double	pow_aux;

	info->ray->cy_x = info->player->player_x;
	info->ray->cy_y = info->player->player_y;
	while (is_wall(info->ray->cy_x, info->ray->cy_y, info) == false)
	{
		if (info->ray->angle > 0 && info->ray->angle < M_PI)
			info->ray->cy_y = ceil(info->ray->cy_y) - 1;
		else
			info->ray->cy_y = floor(info->ray->cy_y) + 1;
		info->ray->cy_x = (info->player->player_y - info->ray->cy_y) / tan(info->ray->angle);
		info->ray->cy_x += info->player->player_x;
	}
	pow_aux = pow(info->player->player_x - info->ray->cy_x, 2);
	pow_aux += pow(info->player->player_y - info->ray->cy_y, 2);
	if (pow_aux > 10000)
		pow_aux = 10000;
	info->ray->dist_y = sqrt(pow_aux);
}


void	calc_collision_x(t_info *info)
{
	double	pow_aux;

	info->ray->cx_x = info->player->player_x;
	info->ray->cx_y = info->player->player_y;
	while (!is_wall(info->ray->cx_x, info->ray->cx_y, info))
	{
		if (info->ray->angle > M_PI_2 && info->ray->angle < (3 * M_PI_2))
			info->ray->cx_x = ceil(info->ray->cx_x) - 1;
		else
			info->ray->cx_x = floor(info->ray->cx_x) + 1;
		info->ray->cx_y = (info->player->player_x - info->ray->cx_x) * tan(info->ray->angle);
		info->ray->cx_y += info->player->player_y;
	}
	pow_aux = pow(info->player->player_x - info->ray->cx_x, 2);
	pow_aux += pow(info->player->player_y - info->ray->cx_y, 2);
	if (pow_aux > 10000)
		pow_aux = 10000;
	info->ray->dist_x = sqrt(pow_aux);
}

void	ray_casting(t_info *info, int x)
{
	double	angle_frac;

	info->ray->angle = info->player->player_angle - (POV_ANGLE / 2);
	angle_frac = (POV_ANGLE / SCR_W);
	info->ray->id = x;
	info->ray->angle = info->ray->angle + angle_frac;
	calc_collision_x(info);
	calc_collision_y(info);
	if (info->ray->dist_x < info->ray->dist_y)
	{
		info->ray->dist = info->ray->dist_x;
		info->ray->tex_start = info->ray->cx_y - floor(info->ray->cx_y);
		if (info->ray->angle > M_PI_2 && info->ray->angle < (3 * M_PI_2))
			info->ray->texture = info->we_txt;
		else
			info->ray->texture = info->no_txt;
	}
	else
	{
		info->ray->dist = info->ray->dist_y;
		info->ray->tex_start = info->ray->cy_x - floor(info->ray->cy_x);
		if (info->ray->angle > 0 && info->ray->angle < M_PI)
			info->ray->texture = info->ea_txt;
		else
			info->ray->texture = info->so_txt;
	}
}
