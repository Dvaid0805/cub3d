/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:12:46 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 12:22:37 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parser(t_parser *parser)
{
	if (parser->no_txt_loc)
		free(parser->no_txt_loc);
	if (parser->so_txt_loc)
		free(parser->so_txt_loc);
	if (parser->we_txt_loc)
		free(parser->we_txt_loc);
	if (parser->ea_txt_loc)
		free(parser->ea_txt_loc);
	ft_split_free(parser->map);
	free(parser);
}
