/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:11:20 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/21 10:14:19 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_init_tmap(t_map *map);
void	ft_init_tgame(t_game *game);
void	ft_end_game(t_game *game);

int	main(int ac, char *av[])
{
	t_map	map;
	t_game	game;

	if (ac != 2)
	{
		write (1, "Error\nMust have one argument: Map file!\n", 40);
		exit (1);
	}
	map.filename = av[1];
	ft_init_tmap(&map);
	ft_valid_map(&map);
	ft_valid_path(&map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (map.width * SIZE), \
		(map.height * SIZE), "so_long");
	ft_init_tgame(&game);
	game.map = &map;
	ft_load_map_to_window(&game);
	mlx_hook(game.win, 17, 0, &ft_end_game, &game);
	mlx_hook(game.win, 2, 0, &ft_key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}

void	ft_init_tmap(t_map *map)
{
	map->height = 1;
	map->width = 0;
	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
	map->count_1 = 0;
	map->count_0 = 0;
	map->player_position = 0;
}

void	ft_init_tgame(t_game *game)
{
	int	size;

	size = SIZE;
	game->collected_c = 0;
	game->moves = 0;
	game->img_p1 = mlx_xpm_file_to_image(game->mlx, "images/p1.xpm", \
		&size, &size);
	game->img_p2 = mlx_xpm_file_to_image(game->mlx, "images/p2.xpm", \
		&size, &size);
	game->img_c1 = mlx_xpm_file_to_image(game->mlx, "images/c1.xpm", \
		&size, &size);
	game->img_c2 = mlx_xpm_file_to_image(game->mlx, "images/c2.xpm", \
		&size, &size);
	game->img_s = mlx_xpm_file_to_image(game->mlx, "images/s.xpm", \
		&size, &size);
	game->img_w = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", \
		&size, &size);
	game->img_e = mlx_xpm_file_to_image(game->mlx, "images/cave.xpm", \
		&size, &size);
}

void	ft_end_game(t_game *game)
{
	free(game->map->map_str);
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}
