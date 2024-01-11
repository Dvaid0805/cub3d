/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:12:46 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 20:04:37 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parser_data(t_info *info)
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
	free(info);
}
