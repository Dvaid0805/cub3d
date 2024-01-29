/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_rectangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:45:49 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/29 17:45:52 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_max_len_map(char **map)
{
	int max_length;
	int row;

	row = 0;
	max_length = 0;
	while (map[row])
	{
		int length = strlen(map[row]);
		if (length > max_length)
			max_length = length;
		row++;
	}
	return (max_length);
}

void make_map_rectangular(char **map)
{
	int max_length;
	int row;

	max_length = get_max_len_map(map);
	row = 0;
	while (map[row])
	{
		int length = strlen(map[row]);
		if (length < max_length)
		{
			int diff = max_length - length;
			char* new_line = malloc((length + diff + 1) * sizeof(char));
			strcpy(new_line, map[row]);
			for (int i = length; i < length + diff; i++)
				new_line[i] = '2';
			new_line[length + diff] = '\0';
			free(map[row]);
			map[row] = new_line;
		}
		row++;
	}
}
