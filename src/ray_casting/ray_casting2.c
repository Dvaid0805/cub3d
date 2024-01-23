/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:25:03 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/23 00:01:47 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ray_step_minus(double x)
{
	if (x - (int)x == 0)
		return (1);
	return (x - (int)x);
}

double	ray_step_plus(double x)
{
	if (x - (int)x == 0)
		return (1);
	return (1 - (x - (int)x));
}
/* 
void	wall_height(t_info *info, t_ray *ray)
{
	
}
 */