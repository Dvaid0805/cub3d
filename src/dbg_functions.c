#include "cub3d.h"

void	dbg_file_data(t_info *info)
{
	int		i;

	i = 0;
	printf("no_txt_loc: %s\n", info->no_txt_loc);
	printf("so_txt_loc: %s\n", info->so_txt_loc);
	printf("we_txt_loc: %s\n", info->we_txt_loc);
	printf("ea_txt_loc: %s\n", info->ea_txt_loc);
	printf("f_color: %d\n", info->f_color);
	printf("c_color: %d\n", info->c_color);
	printf("player position: (%d, %d)\n", info->player_x, info->player_y);
	printf("player sight direction: %f\n", info->player_angle);
	printf("map:\n");
	while (info->map[i])
	{
		printf("%s\n", info->map[i]);
		i++;
	}
}

void	dbg_print_ray(t_ray *ray)
{
	printf("ray: %d    angle: %f\n", ray->start, ray->angle);
	printf("X  lenght: %f  ", ray->dist_x);
	printf("coll. point x: %f  %f       ", ray->cx_x, ray->cx_y);
	printf("Y  lenght: %f  ", ray->dist_y);
	printf("coll. point y: %f  %f\n\n", ray->cy_x, ray->cy_y);
}
