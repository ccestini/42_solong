/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:12:50 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/19 15:46:19 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int		ft_read_map_ber(t_map *map);
int		ft_count_elements(t_map *map, char buff);
char	*ft_load_map(t_map *map);

int	ft_read_map_ber(t_map *map)
{
	int		fd;
	char	buff;
	int		w;

	w = 0;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nMap file not found!\n", 26);
		exit (1);
	}
	while (read(fd, &buff, 1))
	{
		if (!(buff == '1' || buff == '0' || buff == '\n' \
			|| buff == 'C' || buff == 'P' || buff == 'E'))
			return (-1);
		if (buff != '\n' && map->height == 1)
			w++;
		if (buff == '\n')
			map->height++;
		ft_count_elements(map, buff);
	}
	map->width = w;
	close(fd);
	return (0);
}

int	ft_count_elements(t_map *map, char buff)
{
	if (buff == 'C')
		map->count_c++;
	else if (buff == 'P')
		map->count_p++;
	else if (buff == 'E')
		map->count_e++;
	else if (buff == '0')
		map->count_0++;
	else if (buff == '1')
		map->count_1++;
	return (0);
}

char	*ft_load_map(t_map *map)
{
	char	*map_str;
	int		fd;
	int		i;
	char	buff;

	i = 0;
	fd = open(map->filename, O_RDONLY);
	map_str = malloc(sizeof(char) * (map->height * (map->width + 1)));
	if (!map_str)
	{
		write(1, "Error\nNo memory allocated!\n", 27);
		exit (1);
	}
	while (read(fd, &buff, 1))
	{
		map_str[i] = buff;
		if (buff == 'P')
			map->player_position = i;
		i++;
	}
	map_str[i] = '\0';
	map->map_str = map_str;
	close(fd);
	return (map_str);
}
