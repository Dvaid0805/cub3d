/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:47 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/28 13:37:23 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dbg_print_parser(t_parser *parser)
{
	if (parser == NULL)
		return ;
	printf("no_txt_loc: %s\n", parser->no_txt_loc);
	printf("so_txt_loc: %s\n", parser->so_txt_loc);
	printf("we_txt_loc: %s\n", parser->we_txt_loc);
	printf("ea_txt_loc: %s\n", parser->ea_txt_loc);
	printf("f_color: %d\n", parser->f_color);
	printf("c_color: %d\n", parser->c_color);
	printf("player position: (%f, %f)\n", parser->player_x, parser->player_y);
	printf("player sight direction: %f\n", parser->player_angle);
	printf("map:\n");
	for (int i = 0; parser->map[i]; i++)
	{
		printf("%s\n", parser->map[i]);
	}
}

void	dbg_file_data(t_info *info)
{
	dbg_print_parser(info->parser);
	printf((info->no_txt) ? "no_txt: OK\n" : "no_txt: NULL\n");
	printf((info->so_txt) ? "so_txt: OK\n" : "so_txt: NULL\n");
	printf((info->we_txt) ? "we_txt: OK\n" : "we_txt: NULL\n");
	printf((info->ea_txt) ? "ea_txt: OK\n" : "ea_txt: NULL\n");
	printf("c_color: %d\n", info->c_color);
	printf("player position: (%f, %f)\n", info->player->player_x, info->player->player_y);
	printf("player sight direction: %f\n", info->player->player_angle);
	printf("map:\n");
	for (int i = 0; info->map[i]; i++)
	{
		printf("%s\n", info->map[i]);
	}
	printf ("\n");
}

void	dbg_print_ray(t_ray *ray, int percent)
{
	int	iter;
	
	iter = (SCR_W * percent) / 100;
	if (percent % iter == 0)
	{
		printf("ray: %d    angle: %f\n", ray->id, ray->angle);
		printf("X  lenght: %f  ", ray->dist_x);
		printf("coll. point x: %f  %f       ", ray->cx_x, ray->cx_y);
		printf("Y  lenght: %f  ", ray->dist_y);
		printf("coll. point y: %f  %f\ntex_start: %f\n\n", ray->cy_x, ray->cy_y, ray->tex_start);
		printf("\t|Min Dist: %f |\n", ray->dist);
	}
}

void	dbg_print_ray_mini(t_ray *ray, int percent)
{
	int	iter;

	iter = (SCR_W * percent) / 100;
	if (ray->id % iter == 0)
	{
		if (ray->id == 0)
			printf("\n");
		printf("ray: %3d  angle: %.3f  ", ray->id, ray->angle);
		printf("colX: %.3f  %.3f  ", ray->cx_x, ray->cx_y);
		printf("Xlen: %.3f  ", ray->dist_x);
		printf("colY: %.3f  %.3f  ", ray->cy_x, ray->cy_y);
		printf("Ylen: %.3f  ", ray->dist_y);
		if (ray->dist_x < ray->dist_y)
			printf("X  ");
		else
			printf("Y  ");
		printf("CollCell: (%d, %d)", ray->CollCell_X, ray->CollCell_Y);
		if (ray->id == SCR_W / 2)
			printf("      MIDDLE");
		printf("\n");
	}
}
