/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bool_funcs1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:03:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/10 20:40:28 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_acceptable_map_value(t_info *info, char **map, int row, int col)
{
	if (is_valid_map_char(map[row][col]))
	{
		if (map[row][col] == 'N' || map[row][col] == 'S'
			|| map[row][col] == 'W' || map[row][col] == 'E')
		{
			if (info->player_x == -1 && info->player_y == -1)
			{
				info->player_dir = get_player_direction(map[row][col]);
				info->player_x = row;
				info->player_y = col;
				map[row][col] = '0';
			}
			else
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	is_texture_or_color(char *s, bool color_check_bool)
{
	if (color_check_bool && (s[0] == 'F' || s[0] == 'C'))
		return (1);
	else if ((s[0] == 'N' && s[1] == 'O')
		|| (s[0] == 'S' && s[1] == 'O')
		|| (s[0] == 'W' && s[1] == 'E')
		|| (s[0] == 'E' && s[1] == 'A'))
		return (1);
	return (0);
}

bool	is_all_spaces(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_map_char(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E')
		return (true);
	return (false);
}

bool	is_enough_info_oblig_data(t_info *info)
{
	if (info->no_txt_loc == NULL
		|| info->so_txt_loc == NULL
		|| info->we_txt_loc == NULL
		|| info->ea_txt_loc == NULL
		|| info->f_color == -1
		|| info->c_color == -1)
		return (false);
	return (true);
}