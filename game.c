/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:11:01 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/21 09:32:01 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_load_map_to_window(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
void	ft_move(t_game *game, int new_position);
void	ft_load_animation(t_game *game, int x, int y, char a);
void	ft_print_moves_on_screen(t_game *game);

void	ft_load_map_to_window(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (game->map->map_str[i])
	{
		x = (i % (game->map->width + 1)) * SIZE;
		y = (i / (game->map->width + 1)) * SIZE;
		if (game->map->map_str[i] == 'P')
			ft_load_animation(game, x, y, 'p');
		else if (game->map->map_str[i] == 'C')
			ft_load_animation(game, x, y, 'c');
		else if (game->map->map_str[i] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img_e, x, y);
		else if (game->map->map_str[i] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->img_s, x, y);
		else if (game->map->map_str[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_w, x, y);
		i++;
	}
	ft_print_moves_on_screen(game);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		ft_move(game, (game->map->player_position - game->map->width - 1));
	if (keycode == 1 || keycode == 125)
		ft_move(game, (game->map->player_position + game->map->width + 1));
	if (keycode == 0 || keycode == 123)
		ft_move(game, (game->map->player_position - 1));
	if (keycode == 2 || keycode == 124)
		ft_move(game, (game->map->player_position + 1));
	if (keycode == 53)
		ft_end_game(game);
	return (0);
}

void	ft_move(t_game *game, int new_position)
{
	if (game->map->map_str[new_position] == '0' \
		|| game->map->map_str[new_position] == 'C')
	{
		if (game->map->map_str[new_position] == 'C')
			game->collected_c++;
		game->moves++;
		ft_print_moves(game->moves);
		game->map->map_str[new_position] = 'P';
		game->map->map_str[game->map->player_position] = '0';
		game->map->player_position = new_position;
	}
	else if (game->map->map_str[new_position] == 'E')
	{
		if ((game->collected_c - game->map->count_c) == 0)
		{
			game->moves++;
			ft_print_moves(game->moves);
			ft_end_game(game);
		}
	}
	ft_load_map_to_window(game);
}

void	ft_load_animation(t_game *game, int x, int y, char a)
{
	if (a == 'p')
	{
		if (game->moves % 2)
			mlx_put_image_to_window(game->mlx, game->win, game->img_p2, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_p1, x, y);
	}
	if (a == 'c')
	{
		if (game->moves % 2)
			mlx_put_image_to_window(game->mlx, game->win, game->img_c2, x, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_c1, x, y);
	}
}

void	ft_print_moves_on_screen(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 15, 30, 0x000000FF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 15, 50, 0x000000FF, str);
	free (str);
}
