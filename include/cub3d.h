/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:59:52 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/09 14:53:56 by dbredykh         ###   ########.fr       */
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

typedef struct s_info
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	char 		*no_txt_loc;
	char 		*so_txt_loc;
	char 		*we_txt_loc;
	char 		*ea_txt_loc;
	int			f_color;
	int			c_color;
	int 		**map;
	int			player_x;
	int			player_y;
}				t_info;

void	put_usage(void);
void	put_error(char *str);

int check_map_add_data(t_info*info, char *argv);

bool is_texture_or_color(char *s, bool color_check_bool);

#endif
