/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:47 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 11:36:49 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dbg_file_data(t_parser *parser)
{
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
	while (parser->map[i])
	{
		printf("%s\n", parser->map[i]);
		i++;
	}
}
