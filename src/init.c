/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:42:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/08 19:25:22 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// change ply position to 0, and save all info to ifo struct,
// save player x and y to info struct
// EA 0
// NO Pi/2
// WE Pi
// SO 3*Pi / 2

void	change_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = '2';
		i++;
	}
}

char **ft_lst_to_arr(t_list *head)
{
	int i = 0;
	char **map = (char **)malloc(sizeof(char *) * (ft_lstsize(head) + 1));
	while (head)
	{
		map[i] = ft_strdup(head->content);
		change_spaces(map[i]);
		head = head->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int is_expect_map_value(char c, int *player_quan)
{
	if (c == '1' || c== '2' || c == '0'
		|| c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
	{
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			*player_quan += 1;
		return (1);
	}
	else
		return (printf("qwe: %d", c), 0);
}

int is_acceptable_values(char **m)
{
	int	r;
	int	c;
	int	pl_quan;

	r = 0;
	c = 0;
	pl_quan = 0;
	while (m[r])
	{
		c = 0;
		while (m[r][c])
		{
			if (is_expect_map_value(m[r][c], &pl_quan))
			{
				c++;
			}
			else
				return (printf("r: %d, c: %d", r, c), put_error("Error: Wrong map values\n"), 0);
		}
		r++;
	}
	if (pl_quan != 1)
			return (put_error("Error: Wrong player quantity\n"), 0);
	return (1);
}

int is_surrounded_by_ones(char **map)
{
	int r = 0;
	int c = 0;
	while (map[r])
	{
		c = 0;
		while (map[r][c])
		{
			if (map[r][c] == '0' || map[r][c] == 'N' || map[r][c] == 'S' || map[r][c] == 'W' || map[r][c] == 'E')
			{
				if (r == 0 || r == ft_matrxlen(map) - 1 || c == 0 || c == ft_strlen(map[r]) - 1)
					return (put_error("Error: Map is not surrounded by 1s\n"), 0);
				if (map[r - 1][c] == ' ' || map[r + 1][c] == ' '
					|| map[r][c - 1] == ' ' || map[r][c + 1] == ' '
					|| map[r - 1][c - 1] == ' '
					|| map[r - 1][c + 1] == ' ' || map[r + 1][c - 1] == ' '
					|| map[r + 1][c + 1] == ' ')
					return (put_error("Error: Map is not surrounded by 1s\n"), 0);
			}
			c++;
		}
		r++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int		fd;

	info = (t_info *)malloc(sizeof(t_info));
	if (argc < 2)
		put_usage(info);
	fd = open(argv[1], O_RDONLY);
	/* if (fd < 0 || check_map_extension(argv[1]))
		return (free(info), put_error("Error: Wrong map file\n"), 0);
	if (!check_map(info, fd))
		return (free(info), 1); */
	char *line = NULL;
	t_list *head = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	char **map = ft_lst_to_arr(head);
	is_acceptable_values(map);
	is_surrounded_by_ones(map);
	return (0);
}
