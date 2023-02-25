/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:34:55 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/23 13:40:28 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_countnbr(int c)
{
	size_t	count;

	count = 0;
	if (c <= 0)
			count++;
	while (c)
	{
		c /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*p;
	long	nb;

	i = ft_countnbr(n);
	nb = n;
	p = ft_calloc(sizeof(char), (i + 1));
	if (!p)
		return (0);
	if (nb < 0)
	{
		p[0] = '-';
		nb *= -1;
	}
	if (!nb)
		p[0] = '0';
	while (nb > 0)
	{
		p[i - 1] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, (count * size));
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}