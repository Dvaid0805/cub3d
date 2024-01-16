/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:10:17 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/16 18:20:49 by pvilchez         ###   ########.fr       */
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

bool	is_wall(double x, double y, t_info *info)
{
	int		i;
	int		j;

	i = (int)(x);
	j = (int)(y);
	if (info->map[j][i] == '1')
		return (true);
	return (false);
}

void	calc_collision_y(t_info *info, t_ray *ray)
{
	double	pow_aux;

	while (!is_wall(ray->cy_x, ray->cy_y, info))
	{
		if (info->player_angle > 0 && info->player_angle < M_PI)
			ray->cy_y--;
		else
			ray->cy_y++;
		ray->cy_x = (info->player_y - ray->cy_y) / tan(info->player_angle);
		ray->cy_x += info->player_x;
	}
	pow_aux = pow(info->player_x - ray->cy_x, 2);
	pow_aux += pow(info->player_y - ray->cy_y, 2);
	ray->dist_y = sqrt(pow_aux);
}

void	calc_collision_x(t_info *info, t_ray *ray)
{
	double	pow_aux;

	while (!is_wall(ray->cx_x, ray->cx_y, info))
	{
		if (info->player_angle > M_PI_2 && info->player_angle < (3 * M_PI_2))
			ray->cx_x--;
		else
			ray->cx_x++;
		ray->cx_y = (info->player_x - ray->cx_x) * tan(info->player_angle);
		ray->cy_y += info->player_y;
	}
	pow_aux = pow(info->player_x - ray->cx_x, 2);
	pow_aux += pow(info->player_y - ray->cx_y, 2);
	ray->dist_x = sqrt(pow_aux);
}

void	ray_casting(t_info *info)
{
	t_ray	ray;
	double	angle;
	double	angle_frac;
	int		i;

	i = 0;
	angle = info->player_angle - (POV_ANGLE / 2);
	angle_frac = (POV_ANGLE / SCR_W);
	while (i < 10)
	{
		angle = normalize_angle(angle + angle_frac * i);
		calc_collision_x(info, &ray);
		calc_collision_y(info, &ray);
		//draw_col(info, &ray, i);
		dbg_print_ray(&ray, i);
		i++;
	}
}
