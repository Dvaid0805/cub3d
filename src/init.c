/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:42:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/03 12:58:17 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int argc, char **argv)
{
	t_info	*info;

	(void) argv;
	info = (t_info *)malloc(sizeof(t_info));
	if (argc < 2)
		put_usage(info);
	return (0);
}
