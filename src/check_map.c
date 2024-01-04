/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:13:59 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/04 19:16:03 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_filename(char *map)
{
	int	len;

	len = ft_strlen(map);
	return (map[len - 1] != 'b'
		|| map[len - 2] != 'u'
		|| map[len - 3] != 'c' || map[len - 4] != '.');
}

static char	*del_space_dup(char *str)
{
	char	*temp;
	int		len;

	temp = str;
	len = ft_strlen(temp);
	while (len > 0 && (temp[len - 1] == ' ' || temp[len - 1] == '\n'))
		len--;
	while (*temp == ' ')
		temp++;
	return (ft_substr(temp, 0, len - (temp - str)));
}

static int	check_texture(char *line, t_info *info)
{
	int		fd;
	char	*texture_loc;

	texture_loc = del_space_dup(line + 2);
	fd = open(texture_loc, O_RDONLY);
	if (fd < 0)
		return (put_error("Error: Can't open texture\n"), 0);
	if (line[0] == 'N' && line[1] == 'O')
		info->no_txt_loc = texture_loc;
	else if (line[0] == 'S' && line[1] == 'O')
		info->so_txt_loc = texture_loc;
	else if (line[0] == 'W' && line[1] == 'E')
		info->we_txt_loc = texture_loc;
	else if (line[0] == 'E' && line[1] == 'A')
		info->ea_txt_loc = texture_loc;
	return (close(fd), 1);
}

int	check_map(t_info *info, int fd)
{
	char	*line;
	int		res;

	res = 1;
	line = NULL;
	while (res && get_next_line(fd, &line))
	{
		if (res && ((line[0] == 'N' && line[1] == 'O')
				|| (line[0] == 'S' && line[1] == 'O')
				|| (line[0] == 'W' && line[1] == 'E')
				|| (line[0] == 'E' && line[1] == 'A')))
			res = check_texture(line, info);
		free(line);
	}
	return (1);
}
