/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:51:26 by amrakouk          #+#    #+#             */
/*   Updated: 2026/11/09 12:48:42 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
