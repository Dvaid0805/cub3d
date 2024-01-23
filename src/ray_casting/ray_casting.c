/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:10:17 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/23 20:35:33 by pvilchez         ###   ########.fr       */
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

void	calc_collision_y(t_info *info, t_ray *ray)
{
	double	pow_aux;

	ray->cy_x = info->player->player_x;
	ray->cy_y = info->player->player_y;
	printf("collision Y\n");
	while (is_wall(ray->cy_x, ray->cy_y, info) == false)
	{
		if (ray->angle > 0 && ray->angle < M_PI)
			ray->cy_y = ceil(ray->cy_y) - 1;
		else
			ray->cy_y = floor(ray->cy_y) + 1;
		ray->cy_x = (info->player->player_y - ray->cy_y) / tan(ray->angle);
		ray->cy_x += info->player->player_x;
	}
	pow_aux = pow(info->player->player_x - ray->cy_x, 2);
	pow_aux += pow(info->player->player_y - ray->cy_y, 2);
	if (pow_aux > 10000)
		pow_aux = 10000;
	ray->dist_y = sqrt(pow_aux);
}


void	calc_collision_x(t_info *info, t_ray *ray)
{
	double	pow_aux;

	ray->cx_x = info->player->player_x;
	ray->cx_y = info->player->player_y;
	printf("collision X\n");
	while (!is_wall(ray->cx_x, ray->cx_y, info))
	{
		if (ray->angle > M_PI_2 && ray->angle < (3 * M_PI_2))
			ray->cx_x = ceil(ray->cx_x) - 1;
		else
			ray->cx_x = floor(ray->cx_x) + 1;
		ray->cx_y = (info->player->player_x - ray->cx_x) * tan(ray->angle);
		ray->cx_y += info->player->player_y;
	}
	pow_aux = pow(info->player->player_x - ray->cx_x, 2);
	pow_aux += pow(info->player->player_y - ray->cx_y, 2);
	if (pow_aux > 10000)
		pow_aux = 10000;
	ray->dist_x = sqrt(pow_aux);
}

void	ray_casting(t_info *info)
{
	t_ray	ray;
	double	angle_frac;
	int		i;

	i = 0;
	ray.angle = info->player->player_angle - (POV_ANGLE / 2);
	angle_frac = (POV_ANGLE / SCR_W);
	while (i < SCR_W)
	{
		ray.id = i;
		ray.angle = ray.angle + angle_frac;
		calc_collision_x(info, &ray);
		calc_collision_y(info, &ray);
		if (ray.dist_x < ray.dist_y)
		{
			ray.dist = ray.dist_x;
			ray.tex_start = ray.cx_y - floor(ray.cx_y);
			if (ray.angle > M_PI_2 && ray.angle < (3 * M_PI_2))
				ray.texture = info->we_txt;
			else
				ray.texture = info->ea_txt;
		}
		else
		{
			ray.dist = ray.dist_y;
			ray.tex_start = ray.cy_x - floor(ray.cy_x);
			if (ray.angle > 0 && ray.angle < M_PI)
				ray.texture = info->no_txt;
			else
				ray.texture = info->so_txt;
		}
		//draw_col(info, &ray, i);
		dbg_print_ray(&ray);
		i++;
	}
}
