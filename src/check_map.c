/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:13:59 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/05 17:29:29 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	return (map[len - 1] != 'b'
		|| map[len - 2] != 'u'
		|| map[len - 3] != 'c' || map[len - 4] != '.');
}

int	check_map(t_info *info, int fd)
{
	char	*line;
	int		res;

	res = 1;
	while (res && get_next_line(fd, &line))
	{
		if (res && ((line[0] == 'N' && line[1] == 'O')
				|| (line[0] == 'S' && line[1] == 'O')
				|| (line[0] == 'W' && line[1] == 'E')
				|| (line[0] == 'E' && line[1] == 'A')))
			res = get_texture(line, info);
		else if (res && ((line[0] == 'F') || (line[0] == 'C')))
			res = get_color(line, info);
		free(line);
	}
	return (res);
}
