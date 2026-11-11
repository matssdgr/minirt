/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoguely <mgoguely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:34:55 by amine             #+#    #+#             */
/*   Updated: 2026/11/11 19:55:10 by mgoguely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing_bonus.h"

static void free_lights(t_scene *s)
{
	t_light *cur;
	t_light *next;

	cur = s->lights;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	s->lights = NULL;
}

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
	free_lights(s);
}
