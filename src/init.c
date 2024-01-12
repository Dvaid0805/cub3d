/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:42:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/12 19:20:44 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parser_init_info(t_info *info)
{
	info->map = ft_calloc(sizeof(char *), 1);
	if (!info->map)
		unplanned_exit(info, E_MEMORY);
	info->map[0] = NULL;
	info->no_txt_loc = NULL;
	info->so_txt_loc = NULL;
	info->we_txt_loc = NULL;
	info->ea_txt_loc = NULL;
	info->f_color = -1;
	info->c_color = -1;
	info->player_x = -1;
	info->player_y = -1;
	info->player_dir = -1;
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 2)
		return (put_usage(), 1);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (put_error(E_MEMORY, 0), 1);
	parser_init_info(info);
	map_parsing(info, argv[1]);
	dbg_file_data(info);
	free_parser_data(info);
	return (0);
}
