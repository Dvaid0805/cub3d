/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:38 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/17 17:56:40 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void steal_parser_data(t_info *info)
{
	info->no_txt = mlx_load_png(info->parser->no_txt_loc);
	info->so_txt = mlx_load_png(info->parser->so_txt_loc);
	info->we_txt = mlx_load_png(info->parser->we_txt_loc);
	info->ea_txt = mlx_load_png(info->parser->ea_txt_loc);
	free(info->map);
	info->map = info->parser->map;
	info->player->player_x = info->parser->player_x;
	info->player->player_y = info->parser->player_y;
	info->player->player_angle = info->parser->player_angle;
	info->f_color = info->parser->f_color;
	info->c_color = info->parser->c_color;
	free(info->parser->no_txt_loc);
	free(info->parser->so_txt_loc);
	free(info->parser->we_txt_loc);
	free(info->parser->ea_txt_loc);
	free(info->parser);
	info->parser = NULL;
}

static void init_structs(t_info *info)
{
	info->player = (t_player *)malloc(sizeof(t_player));
	if (!info->player)
		unplanned_exit(info, E_MEMORY);
	info->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!info->ray)
		unplanned_exit(info, E_MEMORY);
	steal_parser_data(info);
}

static t_info	*initial_info(void)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		unplanned_exit(info, E_MEMORY);
	info->parser = (t_parser *)malloc(sizeof(t_parser));
	if (!info->parser)
		unplanned_exit(info, E_MEMORY);
	info->player = NULL;
	info->ray = NULL;
	info->mlx = NULL;
	info->img = NULL;
	info->no_txt = NULL;
	info->so_txt = NULL;
	info->we_txt = NULL;
	info->ea_txt = NULL;
	info->map = ft_calloc(1, sizeof(char *));
	info->map[0] = NULL;
	info->f_color = -1;
	info->c_color = -1;
	return (info);
}

void init(char **argv)
{
	t_info *info;

	info = initial_info();
	parser_init(info, argv[1]);
	init_structs(info);
	graphic_init(info);
	/* dbg_file_data(info);
	ray_casting(info); */
	general_free(info);
}
