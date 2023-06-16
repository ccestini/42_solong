/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:12:15 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/19 15:46:19 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_valid_map(t_map *map);
int	ft_valid_filetype(t_map *map);
int	ft_valid_chars(t_map *map);
int	ft_valid_rectangle(t_map *map);
int	ft_valid_walls(t_map *map);

int	ft_valid_map(t_map *map)
{
	if (ft_valid_filetype(map) != 0)
	{
		write (1, "Error\nInvalid file extension. Use *.ber!\n", 41);
		exit (1);
	}
	if (ft_valid_chars(map) != 0)
		exit (1);
	ft_load_map(map);
	if (ft_valid_rectangle(map) != 0)
	{
		write (1, "Error\nMap is not a rectangle\n", 29);
		free(map->map_str);
		exit (1);
	}
	if (ft_valid_walls(map) != 0)
	{
		write (1, "Error\nMap is not surrounded by walls\n", 37);
		free(map->map_str);
		exit (1);
	}
	return (0);
}

int	ft_valid_filetype(t_map *map)
{
	char	*filetype;
	int		i;
	int		j;
	int		n;

	filetype = ".ber";
	n = 4;
	i = ft_strlen(map->filename) - 1;
	j = ft_strlen(filetype) -1;
	if (!map->filename || !filetype || i <= j)
		return (-1);
	while (n--)
	{
		if ((map->filename[i] == filetype[j]) && map->filename && filetype)
		{
			i--;
			j--;
		}
		else
			return (-1);
	}
	return (0);
}

int	ft_valid_chars(t_map *map)
{
	if (ft_read_map_ber(map) == -1)
	{
		write(1, "Error\nMap with invalid character!\n", 34);
		return (-1);
	}
	if (map->count_p != 1)
	{
		write(1, "Error\nMap must have 1 Player!\n", 30);
		return (-1);
	}
	if (map->count_c < 1)
	{
		write(1, "Error\nMap needs at least 1 Collectible!\n", 40);
		return (-1);
	}
	if (map->count_e != 1)
	{
		write(1, "Error\nMap must have 1 Exit!\n", 28);
		return (-1);
	}
	return (0);
}

int	ft_valid_rectangle(t_map *map)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (map->map_str[i])
	{
		if (map->map_str[i] != '\n')
			w++;
		if (map->map_str[i] == '\n')
		{
			if (map->width != w)
				return (-1);
			w = 0;
		}
		i++;
	}
	if (map->map_str[i] == '\0' && map->width != w)
		return (-1);
	return (0);
}

int	ft_valid_walls(t_map *map)
{
	int	n;
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map->map_str);
	n = map->width;
	while (n--)
	{
		if (map->map_str[i] != '1' || map->map_str[len -1] != '1')
			return (-1);
		i++;
		len--;
	}
	i = 0;
	while (map->map_str[i])
	{
		if (map->map_str[i] == '\n' && map->map_str[i - 1] != '1')
			return (-1);
		if (map->map_str[i] == '\n' && map->map_str[i + 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
