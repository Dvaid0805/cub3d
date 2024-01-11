/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:00 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 15:56:42 by dbredykh         ###   ########.fr       */
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

int	map_parsing(t_info *info, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	line = NULL;
	if (fd < 0 || !is_valid_map_extension(argv))
		return (put_error(E_INVALID_FILE, 0), 0);
	if (!check_map_oblig_data(info, fd, line))
		return (put_error(E_OBLIG_DATA, 0), close(fd), free(line), 0);
	if (!is_enough_info_oblig_data(info))
		return (put_error(E_OBLIG_DATA, 0), 0);
	if (!check_map_format(info, fd, line))
		return (put_error(E_INVALID_MAP, 0), 0);
	return (1);
}
