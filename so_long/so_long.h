/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:55:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/21 18:58:03 by aamhal           ###   ########.fr       */
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

typedef struct s_so_long
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
	char	**map;
	int		rows;
	int		columns;
	int 	p;
	int		c;
	int		e;
	int 	px;
	int		py;
	
}t_sl;

int 	win_view(t_sl *sl);
int		ft_first_w(char *line,t_sl *sl );
int		ft_sides(char *line,t_sl *sl );
int		s_valid(char c);
int		ft_last(char *line,t_sl *sl );
int 	check_char(t_sl *sl);
void 	put_img(t_sl *sl);
void 	map_resolution(t_sl *sl);
void 	put_player(t_sl *sl);
void 	put_coin(t_sl *sl);
void 	put_exit(t_sl *sl);
void 	put_wall(t_sl *sl);
void	put_sky(t_sl *sl);
void 	find_player(t_sl *sl);
int 	ft_close(t_sl *sl);
int 	key_hook(int key,t_sl *sl);
int moves(int key, t_sl *sl);

#endif