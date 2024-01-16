/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplanned_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:24:49 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 11:35:15 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	unplanned_exit(t_parser *parser, int error_code)
{
	if (parser)
		free_parser_data(parser);
	if (error_code)
		put_error(error_code, 0);
	exit(EXIT_FAILURE);
}
