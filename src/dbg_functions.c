/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:47 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/21 19:57:24 by pvilchez         ###   ########.fr       */
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

void	dbg_print_ray(t_ray *ray)
{
	printf("ray: %d    angle: %f\n", ray->id, ray->angle);
	printf("X  lenght: %f  ", ray->dist_x);
	printf("coll. point x: %f  %f       ", ray->cx_x, ray->cx_y);
	printf("Y  lenght: %f  ", ray->dist_y);
	printf("coll. point y: %f  %f\n\n", ray->cy_x, ray->cy_y);
}
