/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:05 by ccestini          #+#    #+#             */
/*   Updated: 2022/09/21 10:57:15 by ccestini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define SIZE 50

# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	int		height;
	int		width;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_1;
	int		count_0;
	char	*filename;
	char	*map_str;
	int		player_position;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_p1;
	void	*img_p2;
	void	*img_c1;
	void	*img_c2;
	void	*img_s;
	void	*img_w;
	void	*img_e;
	t_map	*map;
	int		collected_c;
	int		moves;
}	t_game;

typedef struct s_queue
{
	int				index;
	struct s_queue	*next;
}	t_queue;

/* Parte 1 - Check Valid Map */
void	ft_init_tmap(t_map *map);
int		ft_valid_map(t_map *map);
int		ft_valid_filetype(t_map *map);
int		ft_valid_chars(t_map *map);
int		ft_read_map_ber(t_map *map);
int		ft_count_elements(t_map *map, char buff);
char	*ft_load_map(t_map *map);
int		ft_valid_rectangle(t_map *map);
int		ft_valid_walls(t_map *map);

/* Parte 2 - Check Valid Map Path */
int		ft_valid_path(t_map *map);
t_queue	*ft_create_queue1(t_map *map, char *map_str_copy, t_queue *queue);
t_queue	*ft_create_queue2(t_map *map, char *map_str_copy, t_queue *queue);
char	*ft_mark_visited(t_queue *queue, char *map_str_copy);

/* Parte 3 - Play Game */
void	ft_init_tgame(t_game *game);
void	ft_load_map_to_window(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
void	ft_move(t_game *game, int new_position);
void	ft_load_animation(t_game *game, int x, int y, char a);
void	ft_print_moves_on_screen(t_game *game);
void	ft_end_game(t_game *game);

/* Parte 4 - Utils from libft */
char	*ft_strdup(char *src);
int		ft_strlen(char *s);
void	ft_putnbr(int n);
void	ft_print_moves(int n);
int		ft_countnbr(long n);
char	*ft_itoa(int n);

/* Parte 4b - Utils2.c = Queue functions for Breadth First Search (BFS) */
t_queue	*ft_queue_new(int index);
void	ft_q_add_back(t_queue **queue, t_queue *new);
void	ft_queue_delete(t_queue **lst);

#endif
