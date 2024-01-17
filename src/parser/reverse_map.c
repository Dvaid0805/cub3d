/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:04:02 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/17 16:04:05 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reverse_map(char **map)
{
    int numLines;
	int i;

	i = 0;
	numLines = 0;
    if (map == NULL)
        return;
    while (map[numLines] != NULL)
        numLines++;
    while (i < numLines / 2)
	{
		char *temp = map[i];
		map[i] = map[numLines - 1 - i];
		map[numLines - 1 - i] = temp;
		i++;
    }
}
