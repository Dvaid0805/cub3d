/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_add_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:33:06 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/09 14:54:45 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*str_get_color(char *line)
{
	char	**color;
	char	*c_line;
	int		*c_arr;
	int		i;

	i = 0;
	c_arr = (int *)malloc(sizeof(int) * 4);
	if (!c_arr)
		return (NULL);
	c_line = ft_str_del_space(line + 1);
	color = ft_split(c_line, ',');
	free(c_line);
	while (i < 3)
	{
		c_arr[i] = ft_atoi(color[i]);
		if (!ft_aredigits(color[i]) || c_arr[i] > 255 || c_arr[i] < 0)
			return (free(c_arr), ft_split_free(color), NULL);
		i++;
	}
	c_arr[i] = '\0';
	return (ft_split_free(color), c_arr);
}

static int	check_map_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	return (map[len - 1] != 'b'
		|| map[len - 2] != 'u'
		|| map[len - 3] != 'c' || map[len - 4] != '.');
}

static int	check_map_color(char *line, t_info *info)
{
	int	*c_arr;

	c_arr = str_get_color(line);
	if (c_arr != NULL)
	{
		if (line[0] == 'F')
			info->c_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 0);
		else if (line[0] == 'C')
			info->f_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 0);
	}
	else
		return (0);
	return (free(c_arr), 1);
}

static int	check_map_textures(char *line, t_info *info)
{
	int		fd;
	char	*texture_loc;

	texture_loc = ft_str_del_space(line + 2);
	fd = open(texture_loc, O_RDONLY);
	if (fd < 0)
		return (0);
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

bool is_texture_or_color(char *s, bool color_check_bool)
{
	if ((s[0] == 'N' && s[1] == 'O')
		|| (s[0] == 'S' && s[1] == 'O')
		|| (s[0] == 'W' && s[1] == 'E')
		|| (s[0] == 'E' && s[1] == 'A'))
		return (1);
	else if (color_check_bool && (s[0] == 'F' || s[0] == 'C'))
		return (1);
	return (0);
}

int check_map_add_data(t_info*info, char *argv)
{
	char 	*s;
	int		fd;

	s = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0 || check_map_extension(argv))
		return (put_error("Error: Wrong map file\n"), 0);
	while (get_next_line(fd, &s))
	{
		if (is_texture_or_color(s, false))
			if (!check_map_textures(s, info))
				return (close(fd),free(s), put_error("Error: Wrong texture data\n"), 0);
		else if (is_texture_or_color(s, true))
			if (check_map_color(s, info))
				return (close(fd), free(s), put_error("Error: Wrong color data\n"), 0);
		free(s);
	}
	return (close(fd), 1);
}
