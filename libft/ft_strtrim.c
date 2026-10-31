/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakouk <amrakouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:20:19 by amrakouk          #+#    #+#             */
/*   Updated: 2025/11/11 17:47:30 by amrakouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	new_str = ft_substr(s1, i, j - i);
	if (!new_str)
		return (NULL);
	return (new_str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*set;
	char	*res;

	s1 = "   hello world   ";
	set = " ";
	res = ft_strtrim(s1, set);
	printf("'%s'\n", res);
	free(res);
}*/
