/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:27:11 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/24 13:45:37 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_y_pixel(int w_start, int w_end, int y, int texture_height)
{
    double	relative_y;
    int		texture_y;

    relative_y = (double)(y - w_start) / (w_end - w_start);
    texture_y = (int)(relative_y * texture_height);
    if (texture_y > texture_height - 1)
        texture_y = texture_height - 1;
    else if (texture_y < 0)
        texture_y = 0;
    return (texture_y);
}

int	get_texture_pixel_color(mlx_texture_t *texture, int y, int x)
{
    uint8_t	*pixel;

    pixel = texture->pixels + (((y * texture->width) + x)
            * texture->bytes_per_pixel);
    return (ft_get_rgba(pixel[0], pixel[1], pixel[2], pixel[3]));
}

void	fill_floor_ceilings_else(t_info *info, int x, int w_start, int w_end)
{
    /* int color;
    int texY; */
    int y;

    y = 1;
    while (y < SCR_H)
    {
        if (y < w_start)
            mlx_put_pixel(info->img, x, y, info->c_color);
        else if (y > w_end)
            mlx_put_pixel(info->img, x, y, info->f_color);
        else
        {
            /* texY = calc_y_pixel(w_start, w_end, y, info->ray->texture->height);
            color = get_texture_pixel_color(info->ray->texture, texY, x);
            mlx_put_pixel(info->img, x, y, color); */
            mlx_put_pixel(info->img, x, y, 0XFF0000FF);
        }
        y++;
    }
}

void  draw(t_info *info)
{
    int x;
    int	w_height;
    int	w_start;
    int	w_end;

    x = 1;
    while (x < SCR_W)
    {
        ray_casting(info, x);
        w_height = SCR_H / info->ray->dist;
        w_start = (SCR_H / 2) - (w_height / 2);
        w_end = (SCR_H / 2) + (w_height / 2);
        fill_floor_ceilings_else(info, x, w_start, w_end);
        x++;
        init_ray(info->ray);
    }
}
