/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:55:57 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/27 18:16:11 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libftprintf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <libc.h>

# define SIZE 64

typedef struct s_so_long
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*sky;
	void	*monster;
	int		weight;
	int		hight;
	int		x;
	int		y;
	int		resx;
	int		resy;
	char	**map;
	int		rows;
	int		columns;
	int		p;
	int		c;
	int		e;
	int		m;
	int		px;
	int		py;
	int		moves;
	int		ppos;
	char	**vpm;
}t_sl;

int		r_c_count(char *av, t_sl *sl);
int		win_view(t_sl *sl);
int		ft_first_w(char *line, t_sl *sl );
int		ft_sides(char *line, t_sl *sl );
int		s_valid(char c);
int		ft_last(char *line, t_sl *sl );
int		check_char(t_sl *sl);
void	put_img(t_sl *sl);
void	map_resolution(t_sl *sl);
void	put_player(t_sl *sl);
void	put_coin(t_sl *sl);
void	put_exit(t_sl *sl);
void	put_wall(t_sl *sl);
void	put_sky(t_sl *sl);
void	find_player(t_sl *sl);
int		ft_close(t_sl *sl);
int		key_hook(int key, t_sl *sl);
int		moves(int key, t_sl *sl);
void	m_right(t_sl*sl);
void	m_left(t_sl*sl);
void	m_up(t_sl*sl);
void	m_down(t_sl*sl);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_countnbr(int c);
void	put_monster(t_sl *sl);
int		new_map(char *av, t_sl *sl);
void	put_p(t_sl *sl, int r, int c, int *f);
void	fill_map(t_sl *sl);
int		ft_mcheck(char **p);
int		valid_path(char *av, t_sl *sl);
int		ft_echeck(char **p);
void	des_img(t_sl *sl);
void	l_exit(t_sl *sl);
void	down_exit(t_sl *sl);
void	up_exit(t_sl *sl);
void	r_exit(t_sl *sl);
void	ft_free(char **p);

#endif