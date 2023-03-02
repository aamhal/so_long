/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:16:34 by aamhal            #+#    #+#             */
/*   Updated: 2023/02/27 18:03:12 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 1

void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_puthexa(unsigned int nbr, int *count, char c);
void	ft_putunbr(unsigned int n, int *count);
void	ft_putadress(unsigned long long n, int *count);
int		ft_printf(const char *s, ...);
// get_next_line
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char	*s);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif