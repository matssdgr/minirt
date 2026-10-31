/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakouk <amrakouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:11:00 by amrakouk          #+#    #+#             */
/*   Updated: 2025/12/10 15:17:30 by amrakouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*le but va etre de se placer sur le dernier element de la liste
	et si son content est un \n je retourne 1. je dois securiser si
	la reserve est NULL je retourne 0.
	if (current->content[i] == '\n')
	pour me placer sur le dernier element de la liste je peux utiliser
	une fonction differente du genre
	t_list	ft_lstlast(t_list *reserve)
		t_list	*current
		current = reserve;
		while (current && current->next)
			current = current->next;
		return (current)
	je me place sur le dernier element pour gagner du temps car si une ligne avec
	un \n a ete renvoyer il sera forcement a la fin donc je check directement
	le dernier element.*/

int	found_newline(t_list *reserve)
{
	int		i;
	t_list	*current;

	if (reserve == NULL)
		return (0);
	current = ft_lstlast(reserve);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *reserve)
{
	t_list	*current;

	current = reserve;
	while (current && current->next)
		current = current->next;
	return (current);
}

/* dans cette fonction je vais devoir extraire tous les caraceres de
	la reserve et les placer dans ma variable ligne.
	Pour cela je vais devoir creer une ligne via une fonction
	qui calcule le nombre de char dans la ligne incluant le \n
	et alloue la memoire */

void	gen_ligne(char **ligne, t_list *reserve)
{
	int	i;
	int	len;

	len = 0;
	while (reserve)
	{
		i = 0;
		while (reserve->content[i])
		{
			len++;
			if (reserve->content[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
		}
		reserve = reserve->next;
	}
	*ligne = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	free_reserve(t_list *reserve)
{
	t_list	*current;
	t_list	*next;

	current = reserve;
	while (current)
	{
		if (current->content)
			free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
