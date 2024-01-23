/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:10:17 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/23 17:29:59 by pvilchez         ###   ########.fr       */
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
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > info->rows)
		x = info->rows;
	if (y > info->columns)
		y = info->columns;
	if (info->map[(int)x][(int)y] != '0')
	{
		printf("%d %d wall\n", (int)x, (int)y);
		return (true);
	}
	printf("%d %d no wall\n", (int)x, (int)y);
	return (false);
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
			ray->cy_y = ray->cy_y - ray_step_minus(info->ray->cy_y);
		else
			ray->cy_y = ray->cy_y + ray_step_plus(info->ray->cy_y);
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
			ray->cx_x = ray->cx_x - ray_step_minus(info->ray->cx_x);
		else
			ray->cx_x = ray->cx_x + ray_step_plus(info->ray->cx_x);
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
	printf("POV_ANGLE: %f   angle_frac: %f\n", POV_ANGLE, angle_frac);
	while (i < SCR_W)
	{
		ray.id = i;
		ray.angle = ray.angle + angle_frac;
		calc_collision_x(info, &ray);
		calc_collision_y(info, &ray);
		wall_height(info, &ray);
		//Davyd's comment: Fix infinity loop
		//Davyd's comment: I need distance = (ray->dist_x / ray->dist_y depends on who has the smaller length) * cos(fabs(ray_angle - player->view_angle)));
		//Davyd's comment: I need textura = (depends on who has the smaller length) ray -> mlx_texture_t * texture = take (no/we/ea/so)_txt depends of angle;
		//draw_col(info, &ray, i);
		dbg_print_ray(&ray);
		i++;
	}
}
