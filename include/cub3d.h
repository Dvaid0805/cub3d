/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/11 20:05:06 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../assets/MLX42/include/MLX42/MLX42.h"
# include "../assets/libft/include/libft.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define SIZE 750

enum	e_ErrorCode
{
	E_MEMORY = 1,
	E_OBLIG_DATA = 2,
	E_INVALID_FILE = 3,
	E_INVALID_MAP = 4
};

typedef struct s_info
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	char		*no_txt_loc;
	char		*so_txt_loc;
	char		*we_txt_loc;
	char		*ea_txt_loc;
	int			f_color;
	int			c_color;
	char		**map;
	int			player_x;
	int			player_y;
	double		player_dir;
}				t_info;

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
	
#endif
