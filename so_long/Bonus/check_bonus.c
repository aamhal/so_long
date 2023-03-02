/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:35:42 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/26 13:51:00 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	l_exit(t_sl *sl)
{
	ft_printf("moves :%d\n", sl->moves++);
	sl->map[sl->py][sl->px] = '0';
	sl->px -= 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}

void	r_exit(t_sl *sl)
{
	ft_printf("moves :%d\n", sl->moves++);
	sl->map[sl->py][sl->px] = '0';
	sl->px += 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}

void	up_exit(t_sl *sl)
{
	ft_printf("moves :%d\n", sl->moves++);
	sl->map[sl->py][sl->px] = '0';
	sl->py -= 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}

void	down_exit(t_sl *sl)
{
	ft_printf("moves :%d\n", sl->moves++);
	sl->map[sl->py][sl->px] = '0';
	sl->py += 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}
