/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:42:08 by dbredykh          #+#    #+#             */
/*   Updated: 2024/01/09 23:30:33 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// change ply position to 0, and save all info to ifo struct
// terminate save map in int **map without errors
// rewriete exist logick 
// save player x and y to info struct
// EA 0
// NO Pi/2
// WE Pi
// SO 3*Pi / 2

/* void	change_spaces(char *str)
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
} */

bool is_valid_map_char(char c)
{
	if (c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E')
			return (true);
	return (false);
}

char *get_valid_map_line(char *line)
{
	int i;
	char *map_line;

	map_line = malloc(ft_strlen(line) * sizeof(char));
	if (!map_line)
		return (NULL);
	i = 0;
	while (i < ft_strlen(line))
	{
		if (is_valid_map_char(line[i]))
			map_line[i] = line[i];
		else
			map_line[i] = '2';
		i++;
	}
	return (map_line);
}

char **read_map(int fd, char *last_line)
{
	char **map;
	char *line;
	int line_count;

	map = NULL;
	line = last_line;
	line_count = 0;
	while (get_next_line(fd, &line))
	{
		map = ft_realloc(map, (line_count + 2) * sizeof(char *));
		map[line_count] = get_valid_map_line(line);
		line_count++;
	}
	map[line_count] = NULL;
	return (map);
}

char **get_map(int fd, char *last_line)
{
	return (read_map(fd, last_line));
}

int check_map(t_info *info, char *argv)
{
	char *line = NULL;
	int fd = open(argv, O_RDONLY);

	while (get_next_line(fd, &line) && is_texture_or_color(line, true))
		free(line);
	char **map = get_map(fd, line);
	/* if (!is_acceptable_values(map) || !is_surrounded_by_ones(map))
		return (0); */
	printf ("%s", map[0]);
	return (1);
}

int	map_parsing(t_info *info, char *argv)
{
/* 	if (!check_map_add_data(info ,argv))
		return (0); */
	if (!check_map(info, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	if (argc < 2)
		return (put_usage(), 1);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (put_error("Error: Can't allocate memory\n"), 1);
	if (!map_parsing(info, argv[1]))
		return (1);
	return (0);
}
