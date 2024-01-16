/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:27:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 11:33:22 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parser_init_struct(t_parser *parser)
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

int	main(int argc, char **argv)
{
	t_parser	*parser;

	if (argc < 2)
		return (put_usage(), 1);
	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return (put_error(E_MEMORY, 0), 1);
	parser_init_struct(parser);
	map_parsing(parser, argv[1]);
	dbg_file_data(parser);
	free_parser_data(parser);
	return (0);
}
