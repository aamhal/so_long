/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:04 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/07 17:05:03 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	moves(int key, t_sl *sl)
{
	if (key == 124 || key == 2)
		m_right(sl);
	if (key == 123 || key == 0)
		m_left(sl);
	if (key == 126 || key == 13)
		m_up(sl);
	if (key == 125 || key == 1)
		m_down(sl);
	return (0);
}

void	m_right(t_sl*sl)
{
	sl->ppos = 1;
	if (sl->map[sl->py][sl->px + 1] == '1')
		return ;
	if (sl->map[sl->py][sl->px + 1] == 'M')
	{
		ft_printf("YOU DIE");
		exit(1);
	}
	else if (sl->map[sl->py][sl->px + 1] == '0')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->px += 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py][sl->px + 1] == 'C')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->px += 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py][sl->px + 1] == 'E' && sl->c == 0)
		r_exit(sl);
}

void	m_left(t_sl*sl)
{
	sl->ppos = 2;
	if (sl->map[sl->py][sl->px - 1] == '1')
		return ;
	if (sl->map[sl->py][sl->px - 1] == 'M')
	{
		ft_printf("YOU DIE");
		exit(1);
	}
	else if (sl->map[sl->py][sl->px - 1] == '0')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->px -= 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py][sl->px - 1] == 'C')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->px -= 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py][sl->px - 1] == 'E' && sl->c == 0)
		l_exit(sl);
}

void	m_up(t_sl *sl)
{
	if (sl->map[sl->py - 1][sl->px] == '1')
		return ;
	if (sl->map[sl->py - 1][sl->px] == 'M')
	{
		ft_printf("YOU DIE");
		exit(1);
	}
	else if (sl->map[sl->py - 1][sl->px] == '0')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->py -= 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py - 1][sl->px] == 'C')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->py -= 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py - 1][sl->px] == 'E' && sl->c == 0)
		up_exit(sl);
}

void	m_down(t_sl *sl)
{
	if (sl->map[sl->py + 1][sl->px] == '1')
		return ;
	if (sl->map[sl->py + 1][sl->px] == 'M')
	{
		ft_printf("YOU DIE");
		exit(1);
	}
	else if (sl->map[sl->py + 1][sl->px] == '0')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->py += 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py + 1][sl->px] == 'C')
	{
		sl->moves++;
		sl->map[sl->py][sl->px] = '0';
		sl->py += 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py + 1][sl->px] == 'E' && sl->c == 0)
		down_exit(sl);
}
