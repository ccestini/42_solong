/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:12:00 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/21 10:38:15 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int		ft_valid_path(t_map *map);
t_queue	*ft_create_queue(t_map *map, char *map_str_copy, t_queue *queue);
t_queue	*ft_create_queue2(t_map *map, char *map_str_copy, t_queue *queue);
char	*ft_mark_visited(t_queue *queue, char *map_str_copy);

int	ft_valid_path(t_map *map)
{
	int		i;
	char	*map_str_copy;
	t_queue	*queue;

	i = 0;
	map_str_copy = ft_strdup(map->map_str);
	queue = ft_queue_new(map->player_position);
	queue = ft_create_queue(map, map_str_copy, queue);
	queue = ft_create_queue2(map, map_str_copy, queue);
	ft_queue_delete(&queue);
	while (map_str_copy[i] != '\0')
	{
		if (map_str_copy[i] == 'C' || map_str_copy[i] == 'E')
		{
			write (1, "Error\nNo valid path!\n", 21);
			free(map_str_copy);
			free(map->map_str);
			exit (1);
		}
		i++;
	}
	free(map_str_copy);
	return (0);
}

t_queue	*ft_create_queue(t_map *map, char *map_str_copy, t_queue *queue)
{
	t_queue	*ptr1;
	t_queue	*ptr2;

	ptr1 = queue;
	ptr2 = queue;
	while (ptr1)
	{
		if ((map_str_copy[(ptr1->index) + 1] == '0') \
			|| (map_str_copy[(ptr1->index) + 1] == 'C'))
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) + 1));
		if ((map_str_copy[(ptr1->index) - 1] == '0') \
			|| (map_str_copy[(ptr1->index) - 1] == 'C'))
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) - 1));
		if ((map_str_copy[(ptr1->index) - map->width - 1] == '0') \
			|| (map_str_copy[(ptr1->index) - map->width - 1] == 'C'))
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) - map->width - 1));
		if ((map_str_copy[(ptr1->index) + map->width + 1] == '0') \
			|| (map_str_copy[(ptr1->index) + map->width + 1] == 'C'))
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) + map->width + 1));
		map_str_copy = ft_mark_visited(ptr1, map_str_copy);
		ptr1 = ptr2->next;
		ptr2 = ptr2->next;
	}
	return (queue);
}

t_queue	*ft_create_queue2(t_map *map, char *map_str_copy, t_queue *queue)
{
	t_queue	*ptr1;
	t_queue	*ptr2;

	ptr1 = queue;
	ptr2 = queue;
	while (ptr1)
	{
		if (map_str_copy[(ptr1->index) + 1] == 'E')
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) + 1));
		if (map_str_copy[(ptr1->index) - 1] == 'E')
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) - 1));
		if (map_str_copy[(ptr1->index) - map->width - 1] == 'E')
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) - map->width - 1));
		if (map_str_copy[(ptr1->index) + map->width + 1] == 'E')
			ft_q_add_back(&ptr1, ft_queue_new((ptr1->index) + map->width + 1));
		map_str_copy = ft_mark_visited(ptr1, map_str_copy);
		ptr1 = ptr2->next;
		ptr2 = ptr2->next;
	}
	return (queue);
}

char	*ft_mark_visited(t_queue *queue, char *map_str_copy)
{
	t_queue	*ptr1;
	int		i;

	ptr1 = queue;
	while (ptr1)
	{
		i = ptr1->index;
		map_str_copy[i] = 'V';
		ptr1 = ptr1->next;
	}
	return (map_str_copy);
}
