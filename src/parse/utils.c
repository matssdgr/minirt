/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:34:55 by amine             #+#    #+#             */
/*   Updated: 2026/10/29 12:36:44 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

void    free_scene(t_scene *s)
{
    t_object    *cur;
    t_object    *next;

    cur = s->objects;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    s->objects = NULL;
}
