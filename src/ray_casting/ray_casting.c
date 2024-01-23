/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:10:17 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/23 15:33:39 by dbredykh         ###   ########.fr       */
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
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	if (info->map[j][i] == '1')
		return (true);
	return (false);
}

void	calc_collision_y(t_info *info, t_ray *ray)
{
	double	pow_aux;

	ray->cx_x = info->player->player_x;
	ray->cx_y = info->player->player_y;
	while (!is_wall(ray->cy_x, ray->cy_y, info))
	{
		printf("entrando\n");
		if (ray->angle > 0 && ray->angle < M_PI)
			ray->cy_y--;
		else
			ray->cy_y++;
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
	while (!is_wall(ray->cx_x, ray->cx_y, info))
	{
		if (ray->angle > M_PI_2 && ray->angle < (3 * M_PI_2))
			ray->cx_x--;
		else
			ray->cx_x++;
		ray->cx_y = (info->player->player_x - ray->cx_x) * tan(ray->angle);
		ray->cy_y += info->player->player_y;
	}
	pow_aux = pow(info->player->player_x - ray->cx_x, 2);
	pow_aux += pow(info->player->player_y - ray->cx_y, 2);
	if (pow_aux > 10000)
		pow_aux = 10000;
	ray->dist_x = sqrt(pow_aux);
}

void	ray_casting(t_info *info, int x)
{
	t_ray	ray;
	double	angle_frac;

	printf("player angle: %f   POV_angle: %f\n", info->player->player_angle, POV_ANGLE);
	ray.angle = info->player->player_angle - (POV_ANGLE / 2);
	printf("ray angle: %f\n", ray.angle);
	angle_frac = (POV_ANGLE / SCR_W);
	ray.start = x;
	ray.angle = normalize_angle(ray.angle + angle_frac * x);
	/* calc_collision_x(info, &ray);
	calc_collision_y(info, &ray); */
	/* dbg_print_ray(&ray); */
}
