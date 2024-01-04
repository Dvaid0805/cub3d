/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:42:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/04 19:16:40 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	int		fd;

	info = (t_info *)malloc(sizeof(t_info));
	if (argc < 2)
		put_usage(info);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || check_filename(argv[1]))
		return (put_error("Error: map\n"), 0);
	if (!check_map(info, fd))
		return (free(info), 1);
	return (0);
}
