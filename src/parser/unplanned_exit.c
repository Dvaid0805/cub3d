/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplanned_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:24:49 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 15:40:45 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	error_case_info_free(t_info *info)
{
	if (info->no_txt_loc)
		free(info->no_txt_loc);
	if (info->so_txt_loc)
		free(info->so_txt_loc);
	if (info->we_txt_loc)
		free(info->we_txt_loc);
	if (info->ea_txt_loc)
		free(info->ea_txt_loc);
	ft_split_free(info->map);
/* 		if (info->sprite_txt_loc)
		free(info->sprite_txt_loc);
	if (info->z_buffer)
		free(info->z_buffer);
	if (info->sprite)
		free(info->sprite);
	if (info->sprite_order)
		free(info->sprite_order);
	if (info->sprite_distance)
		free(info->sprite_distance); */
	free(info);
}

void	unplanned_exit(t_info *info, int error_code)
{
	if (info)
		error_case_info_free(info);
	if (error_code)
		put_error(error_code, 0);
	exit(EXIT_FAILURE);
}
