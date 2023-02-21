/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:55:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 17:51:50 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <libc.h>

# define SIZE 64

typedef	struct s_so_long
{
	char	**map;
	int		rows;
	int		columns;
	int 	player;
	int		coins;
	int		exit;
	int 	x;
	int		y;

}t_l;

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *player;
	void *coin;
	void *exit;
	void *wall;
	void *sky;
	int weight;
	int hight;
	int x;
	int y;
	int resx;
	int resy;
	t_l *map;
	
}t_mlx;

int 	win_view(t_l *l,t_mlx *mlx);
int		ft_first_w(char *line, t_l *l);
int		ft_sides(char *line, t_l *l);
int		s_valid(char c);
int		ft_last(char *line, t_l *l);
int 	check_char(t_l *l);
void 	put_img(t_l *l, t_mlx *mlx);
void 	map_resolution(t_l *l, t_mlx *mlx);
void 	put_player(t_mlx *mlx);
void 	put_coin(t_mlx *mlx);
void 	put_exit(t_mlx *mlx);
void 	put_wall(t_mlx *mlx);
void	put_sky(t_mlx *mlx);
void 	find_player(t_l *l);
int 	ft_close(t_mlx *mlx);
int key_hook(int key,t_mlx *mlx);
int 	moves(int key, t_l *l);

#endif