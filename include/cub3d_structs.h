/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:55:58 by pvilchez          #+#    #+#             */
/*   Updated: 2024/01/16 11:33:11 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include "cub3d.h"

//t_ray launch_ray(t_info *info, t_player *player);
//void draw_ray(t_info *info, t_ray *ray, int x);

typedef struct s_ray
{
	double		draw_dist;
	double		delta_dist_y;
}				t_ray;

typedef struct s_player
{
	double		player_x;
	double		player_y;
	double		player_dir;
}		t_player;

typedef struct s_parser
{
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
}				t_parser;

typedef struct s_mlx_info
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
}		s_mlx_info;

typedef struct s_info
{
	struct s_mlx		*mlx_info;
	struct s_player		*player;
	struct s_parser		*parser;
	struct s_ray		*ray;
}				t_info;

#endif
