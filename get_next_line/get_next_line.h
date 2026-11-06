/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:10:34 by amrakouk          #+#    #+#             */
/*   Updated: 2026/11/06 07:51:19 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);

int		found_newline(t_list *reserve);
t_list	*ft_lstlast(t_list *reserve);
void	gen_ligne(char **ligne, t_list *reserve);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);
void	read_et_reserve(int fd, t_list **reserve);
void	put_in_reserve(t_list **reserve, char *buf, int lu);
void	extraire_ligne(t_list *reserve, char **ligne, int j);
void	maj_reserve(t_list **reserve);
void	free_reserve(t_list *reserve);

#endif
