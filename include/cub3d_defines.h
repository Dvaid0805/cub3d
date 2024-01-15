/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:58 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/15 13:15:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# include "cub3d.h"

# define SCR_H 600
# define SCR_W 1024
# define C_SIZE 8

enum	e_ErrorCode
{
	E_MEMORY = 1,
	E_OBLIG_DATA = 2,
	E_INVALID_FILE = 3,
	E_INVALID_MAP = 4
};

#endif