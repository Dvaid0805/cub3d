/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:00 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 11:54:36 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_player_direction(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'N')
		return (M_PI / 2.0);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'S')
		return ((3 * M_PI) / 2.0);
	return (-1);
}

static int	is_valid_map_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	return (map[len - 1] == 'b' && map[len - 2] == 'u'
		&& map[len - 3] == 'c' && map[len - 4] == '.');
}

void	map_parsing(t_parser *parser, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = NULL;
	parser_init_data(parser);
	if (fd < 0 || !is_valid_map_extension(argv))
		unplanned_exit(parser, E_INVALID_FILE);
	if (!check_map_oblig_data(parser, fd, line))
		unplanned_exit(parser, E_OBLIG_DATA);
	if (!is_enough_parser_oblig_data(parser))
		unplanned_exit(parser, E_OBLIG_DATA);
	if (!check_map_format(parser, fd, line))
		unplanned_exit(parser, E_INVALID_MAP);
}
