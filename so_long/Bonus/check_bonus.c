/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:35:42 by aamhal            #+#    #+#             */
/*   Updated: 2023/03/07 17:05:48 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	l_exit(t_sl *sl)
{
	sl->moves++;
	sl->map[sl->py][sl->px] = '0';
	sl->px -= 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}

void	r_exit(t_sl *sl)
{
	sl->moves++;
	sl->map[sl->py][sl->px] = '0';
	sl->px += 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}

void	up_exit(t_sl *sl)
{
	sl->moves++;
	sl->map[sl->py][sl->px] = '0';
	sl->py -= 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}

void	down_exit(t_sl *sl)
{
	sl->moves++;
	sl->map[sl->py][sl->px] = '0';
	sl->py += 1;
	sl->map[sl->py][sl->px] = 'P';
	exit(1);
}
