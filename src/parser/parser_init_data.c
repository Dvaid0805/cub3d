/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:51:57 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 11:54:57 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser_init_data(t_parser *parser)
{
	parser->map = ft_calloc(sizeof(char *), 1);
	if (!parser->map)
		unplanned_exit(parser, E_MEMORY);
	parser->map[0] = NULL;
	parser->no_txt_loc = NULL;
	parser->so_txt_loc = NULL;
	parser->we_txt_loc = NULL;
	parser->ea_txt_loc = NULL;
	parser->f_color = -1;
	parser->c_color = -1;
	parser->player_x = -1;
	parser->player_y = -1;
	parser->player_dir = -1;
}
