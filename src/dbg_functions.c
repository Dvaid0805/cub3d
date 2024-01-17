/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:47 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/17 12:03:11 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dbg_print_parser(t_parser *parser)
{
	if (parser == NULL)
		return ;
	int		i;

	i = 0;
	printf("no_txt_loc: %s\n", parser->no_txt_loc);
	printf("so_txt_loc: %s\n", parser->so_txt_loc);
	printf("we_txt_loc: %s\n", parser->we_txt_loc);
	printf("ea_txt_loc: %s\n", parser->ea_txt_loc);
	printf("f_color: %d\n", parser->f_color);
	printf("c_color: %d\n", parser->c_color);
	printf("player position: (%d, %d)\n", parser->player_x, parser->player_y);
	printf("player sight direction: %f\n", parser->player_dir);
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
	printf("f_color: %d\n", info->f_color);
	printf("player position: (%f, %f)\n", info->player->player_x, info->player->player_y);
	printf("player sight direction: %f\n", info->player->player_dir);
	printf("map:\n");
	for (int i = 0; info->map[i]; i++)
	{
		printf("%s\n", info->map[i]);
	}
	printf ("\n");
}
