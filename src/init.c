/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:41:38 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/16 16:27:38 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	*init_info(void)
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		unplanned_exit(info, E_MEMORY);
	info->parser = (t_parser *)malloc(sizeof(t_parser));
	if (!info->parser)
		unplanned_exit(info, E_MEMORY);
	info->player = NULL;
	info->ray = NULL;
	info->mlx = NULL;
	info->img = NULL;
	return (info);
}

void ft_hook(void* param)
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void mlx_init_struct(t_info *info)
{
	info->mlx = mlx_init(SCR_W, SCR_H, "cub3D", false);
	if (!info->mlx)
		unplanned_exit(info, E_MLX);
	info->img = mlx_new_image(info->mlx, SCR_W, SCR_H);
	if (!info->img)
		unplanned_exit(info, E_MLX);
	mlx_image_to_window(info->mlx, info->img, 0, 0);
	mlx_loop_hook(info->mlx, ft_hook, info->mlx);
	mlx_loop(info->mlx);
}

void init_structs(t_info *info)
{
	info->player = (t_player *)malloc(sizeof(t_player));
	if (!info->player)
		unplanned_exit(info, E_MEMORY);
	info->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!info->ray)
		unplanned_exit(info, E_MEMORY);
	mlx_init_struct(info);
}

void init(char **argv)
{
	t_info *info;

	info = init_info();
	parser_init(info, argv[1]);
	init_structs(info);
	dbg_file_data(info->parser);
	general_free(info);
}
