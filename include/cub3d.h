/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/17 13:15:19 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../assets/MLX42/include/MLX42/MLX42.h"
# include "../assets/libft/include/libft.h"
# include "cub3d_defines.h"
# include "cub3d_structs.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// prevent leeks
void		free_parser_data(t_info *info);

// additional functions
void		put_usage(void);
const char	*get_error_message(enum e_ErrorCode code);
void		put_error(int error_num, char *custom_message);
void		unplanned_exit(t_info *info, int error_code);

// map_parsing.c
void		map_parsing(t_info *info, char *argv);
int			check_map_oblig_data(t_info *info, int fd, char *line);
int			check_map_format(t_info *info, int fd, char *line);
double		get_player_direction(char c);

// is_bool_functions.c
bool		is_acceptable_map_value(t_info *info, char **map, int row, int col);
bool		is_texture_or_color(char *s, bool color_check_bool);
bool		is_all_spaces(const char *str);
bool		is_valid_map_char(char c);
bool		is_enough_info_oblig_data(t_info *info);
bool		is_map_point_by_ones(char **map, int r, int c);
bool		is_map_ages_ones(char **map, int r, int c);

// ray_casting.c
void		ray_casting(t_info *info);

// drawing_walls.c
void		draw_col(t_info *info, t_ray *ray, int i);

// dbg_functions.c
void		dbg_file_data(t_info *info);
void		dbg_print_ray(t_ray *ray);
#endif
