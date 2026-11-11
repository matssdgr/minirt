/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:28:50 by amine             #+#    #+#             */
/*   Updated: 2026/10/27 13:24:02 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int count_char(const char *s, char c)
{
    int n;

    n = 0;
    while (*s)
    {
        if (*s == c)
            n++;
        s++;
    }
    return (n);
}

int split_len(char **t)
{
    int i;

    i = 0;
    while (t[i])
        i++;
    return (i);
}

void    free_split(char **t)
{
    int i;

    i = 0;
    while (t[i])
        free(t[i++]);
    free(t);
}
