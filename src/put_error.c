/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:51:36 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/10 18:20:04 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_error(int error_num, char *non_oblig_str)
{
	if (non_oblig_str)
		ft_putstr_fd(non_oblig_str, 2);
	else if (error_num == 1)
		ft_putstr_fd("Error: Can't allocate memory\n", 2);
	else if (error_num == 2)
		ft_putstr_fd("Error: Wrong obligatory data\n", 2);
	else if (error_num == 3)
		ft_putstr_fd("Error: Wrong passed file\n", 2);
	else if (error_num == 4)
		ft_putstr_fd("Error: Invalid map format\n", 2);
}
