/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplanned_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:24:49 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 18:31:42 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	unplanned_exit(t_info *info, int error_code)
{
	if (info)
		free_parser_data(info);
	if (error_code)
		put_error(error_code, 0);
	exit(EXIT_FAILURE);
}
