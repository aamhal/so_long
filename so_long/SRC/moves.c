/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:50:04 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/25 15:16:59 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (sl->map[sl->py][sl->px + 1] == '1')
		return ;
	if (sl->map[sl->py][sl->px + 1] == '0')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->px += 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py][sl->px + 1] == 'C')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->px += 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py][sl->px + 1] == 'E' && sl->c == 0)
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->px += 1;
		sl->map[sl->py][sl->px] = 'P';
		exit(1);
	}
}

void	m_left(t_sl*sl)
{
	if (sl->map[sl->py][sl->px - 1] == '1')
		return ;
	if (sl->map[sl->py][sl->px - 1] == '0')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->px -= 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py][sl->px - 1] == 'C')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->px -= 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py][sl->px - 1] == 'E' && sl->c == 0)
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->px -= 1;
		sl->map[sl->py][sl->px] = 'P';
		exit(1);
	}
}

void	m_up(t_sl *sl)
{
	if (sl->map[sl->py - 1][sl->px] == '1')
		return ;
	if (sl->map[sl->py - 1][sl->px] == '0')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->py -= 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py - 1][sl->px] == 'C')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->py -= 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py - 1][sl->px] == 'E' && sl->c == 0)
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->py -= 1;
		sl->map[sl->py][sl->px] = 'P';
		exit(1);
	}
}

void	m_down(t_sl *sl)
{
	if (sl->map[sl->py + 1][sl->px] == '1')
		return ;
	if (sl->map[sl->py + 1][sl->px] == '0')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->py += 1;
		sl->map[sl->py][sl->px] = 'P';
	}
	else if (sl->map[sl->py + 1][sl->px] == 'C')
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->py += 1;
		sl->map[sl->py][sl->px] = 'P';
		sl->c--;
	}
	else if (sl->map[sl->py + 1][sl->px] == 'E' && sl->c == 0)
	{
		ft_printf("moves :%d\n", sl->moves++);
		sl->map[sl->py][sl->px] = '0';
		sl->py += 1;
		sl->map[sl->py][sl->px] = 'P';
		exit(1);
	}
}
