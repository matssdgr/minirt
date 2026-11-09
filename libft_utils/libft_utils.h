/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:56:55 by amrakouk          #+#    #+#             */
/*   Updated: 2026/11/09 12:37:32 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_isdigit(int c);

void	ft_bzero(void *s, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	ft_putstr_fd(const char *str, int fd);

#endif
