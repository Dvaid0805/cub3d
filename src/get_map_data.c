/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:07:38 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/05 17:55:17 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*check_color(char *line)
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

int	get_color(char *line, t_info *info)
{
	int	*c_arr;

	c_arr = check_color(line);
	if (c_arr != NULL)
	{
		if (line[0] == 'F')
			info->c_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 0);
		else if (line[0] == 'C')
			info->f_color = ft_get_rgba(c_arr[0], c_arr[1], c_arr[2], 0);
	}
	else
		return (put_error("Error: Wrong color data\n"), 0);
	return (free(c_arr), 1);
}

int	get_texture(char *line, t_info *info)
{
	int		fd;
	char	*texture_loc;

	texture_loc = ft_str_del_space(line + 2);
	fd = open(texture_loc, O_RDONLY);
	if (fd < 0)
		return (put_error("Error: Cant' open texture\n"), 0);
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
