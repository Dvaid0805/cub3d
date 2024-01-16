/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:20:54 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 16:26:55 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void general_free(t_info *info)
{
	if (info->parser)
		free_parser(info->parser);
	if (info->player)
		free(info->player);
	if (info->mlx != NULL)
		mlx_terminate(info->mlx);
	if (info->ray)
		free(info->ray);
	if (info)
		free(info);
}
