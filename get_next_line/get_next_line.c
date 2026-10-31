/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakouk <amrakouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:10:17 by amrakouk          #+#    #+#             */
/*   Updated: 2025/12/13 16:18:09 by amrakouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*fonctions utiles:
	read: ssize_t read(int fildes, void *buf, size_t nbyte)
	read = read(fd, name_buffer, BUFFER_SIZE)
	BUFFER_SIZE sera choisi lors de la compilation et est defini par
	defaut dans le .h
	variables statique()
	open(): int open(const char *pathname, int flags, ...);
	pathname qui est le chemin vers mon fichier
	flags qui est ce aue je veux faire (O_RDONLY ... etc)
	dernier optionel si O_CREAT est utilise il faut donner les
	permissions comme chmod
	notions utile sur les lc:
	Pour ajouter un Node, on réitère l’opération de création :
	1-déclaration ;
	2-allocation de mémoire ;
	3-affectation de valeur ;
	puis le Node est inséré en définissant :
	4-le Node qui le précède (et doit pointer sur lui) ;
	5-et le Node qui le suit (NULL si c’est le dernier)
	*/

// 3 securites importantes si fd est negatif ; si la taille du
// buffer est <= 0 donc on aura rien a lire / on ne se deplacera pas
// dans la ligne ; et pareil dans la fonction read

// ensuite je dois:
// 1: lire depuis le filedes et ajouter a la lc
//	en utilisant read
// 2: extraire depuis la reserve et mettre dans ligne
// 3: nettoyer la reserve
char	*get_next_line(int fd)
{
	static t_list	*reserve = NULL;
	char			*ligne;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ligne, 0) < 0)
	{
		free_reserve(reserve);
		reserve = NULL;
		return (NULL);
	}
	ligne = NULL;
	read_et_reserve(fd, &reserve);
	if (reserve == NULL)
		return (NULL);
	extraire_ligne(reserve, &ligne, 0);
	if (!ligne)
		return (NULL);
	maj_reserve(&reserve);
	if (ligne[0] == '\0')
	{
		free_reserve(reserve);
		reserve = NULL;
		free(ligne);
		return (NULL);
	}
	return (ligne);
}
/*Pour chaque fonction je dois trouver quels protections je dois
 rajouter et si il faut free ou pas*/

/*dans cette fonction je dois avancer jusqu'a trouver
	un \n une fois trouver.
	Donc ma premiere condition est tant qu'il n'y a pas
	de \n et tant que lu est different de '\0' dans le cas ou il
	n'y aurait pas de \n.
	ensuite je dois gerer si je n'ai rien lu et si la reserve est null
	en n'oubliant pas de free
	puis ensuite je dois reserver ce que j'ai lu avant le \n dans
	la reserve et aussi stocker le nombre de caractere lu dans un int.
	Je vais donc avoir besoin d'une autre fonction pour trouver le
	\n et une autre qui va reserver ce que j'ai lu dans la reserve
	trouvons les prototypes:
	int found_newline(t_list *reserve);
	void put_in_reserve(t_list **reserve, char *buf, int lu);*/

void	read_et_reserve(int fd, t_list **reserve)
{
	char	*buf;
	int		lu;

	lu = 1;
	while (!(found_newline(*reserve)) && lu != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		lu = (int)read(fd, buf, BUFFER_SIZE);
		if (lu == -1)
		{
			free(buf);
			free_reserve(*reserve);
			*reserve = NULL;
			return ;
		}
		if (lu == 0 && *reserve == NULL)
			return (free(buf));
		buf[lu] = '\0';
		put_in_reserve(reserve, buf, lu);
		free(buf);
	}
}

/*cette fonction va nous servir a ajouter le contenu de buf qui
	est ce que read() vient de lire a la fin de la lc qui est (reserve)
	je dois creer un nouveau noeud pour la reserve qui sera le dernier
	de la liste lui allouer de la memoire dans ce noeud on cree une
	zone pour stocker les caracteres lu (new_node->content) = allocation
	ensuite on copie les caracteres lu que le read() a mis dans buf
	dans le nouveau noeud:
	on s'assure que ca boucle jusqu'a ce que read a reellment lu donc
	i<lu et tant que buf[i].
	a chaque tour on avance le i et on copie le caractere correspondant
	new_node->content[i] = buf[i]
	attention bien remettre le \0 a la fin sinon chaine invalide
	new_node->content[i] = '\0';
	exemple si BUFFER_SIZE = 10 pour Bonjour\namine
			read() lit : "bonjour\namine"
			lu = 8 / "bonjour\n"xxxxx
	pas oublier de gerer si la liste est vide
	et pour finir notre fonction on recupere le dernier noeud avec
	notre fonction precedente ft_lstlast et on ajoute le new node
	apres lui.
	last = ft_lstlast(*reserve);
	last->next = new->node;				*/

void	put_in_reserve(t_list **reserve, char *buf, int lu)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (lu + 1));
	if (new_node->content == NULL)
		return (free(new_node));
	i = 0;
	while (i < lu)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*reserve == NULL)
	{
		*reserve = new_node;
		return ;
	}
	last = ft_lstlast(*reserve);
	last->next = new_node;
}

/*dans cette fonction je vais devoir extraire tous les caraceres de
	la reserve et les placer dans ma variable ligne.
	Pour cela je vais devoir creer une ligne via une fonction
	qui calcule le nombre de char dans la ligne incluant le \n
	et alloue la memoire :
	void	gen_ligne(char **ligne, t_list *reserve)
	ensuite demander a la fonction de parcourir chaque noeud
	(reserve) puis ensuite chaque caractere dans reserve->content
	ensuite une fois qu'on rencontre un \n on copie chaque caractere
	dans *line qui est le pointeur ou on va ecrire la ligne extraite
	*/

void	extraire_ligne(t_list *reserve, char **ligne, int j)
{
	int	i;

	if (reserve == NULL)
	{
		*ligne = malloc(1);
		if (!*ligne)
			return ;
		return ((*ligne)[0] = '\0', (void)0);
	}
	gen_ligne(ligne, reserve);
	if (*ligne == NULL)
		return ;
	j = 0;
	while (reserve)
	{
		i = 0;
		while (reserve->content[i])
		{
			(*ligne)[j++] = reserve->content[i];
			if (reserve->content[i++] == '\n')
				return ((*ligne)[j] = '\0', (void)0);
		}
		reserve = reserve->next;
	}
	(*ligne)[j] = '\0';
}

/*dans cette fonction je vais devoir nettoyer ma reserve. J'ai
	precedemment extrait ma ligne depuis ma reserve jusqu'au
	premier \n donc apres ce \n il reste des elements que je vais
	traiter. Pour cela je dois "nettoyer" les elements de la
	reserve que j'ai envoyer dans ma ligne.
	exemple: "bonjour\ntout le monde\nencore du texte"
	apres maj_reserve(): "tout le monde\nencore du texte"
	extraire_ligne() a retirer dans ligne "bonjour\n" et
	maj_reserve doit retirer ce meme "bonjour" de la reserve
	pour laisser seulement ce qui n'a pas ete traiter.
	Afin de faire tout ca on va devoir creer un nouveau noeud
	pour stocker tout apres le \n, ensuite on recupere le dernier
	maillon avec notre fonction ft_lst_last. on avance pour trouver
	soit la fin de la chaine soit un \n.
	Si on trouve un \n on avance pour placer i juste apres le \n
	et donc avoir le reste, une fois qu'on a le reste on alloue
	la memoire pour le reste: ft_strlen(last->content) - i.
	Puis je copie le reste(tout ce qu'il y'a apres le \n)
	dans mon nouveau noeud. Et je ne dois pas oublier de
	free ma reserve puis de remplacer ma reserve par le nouveau
	noeud.*/

void	maj_reserve(t_list **reserve)
{
	int		i;
	int		j;
	t_list	*last;
	t_list	*nv_node;

	nv_node = malloc(sizeof(t_list));
	if (nv_node == NULL || *reserve == NULL)
		return ;
	nv_node->next = NULL;
	last = ft_lstlast(*reserve);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	nv_node->content = malloc(ft_strlen(last->content) - i + 1);
	if (nv_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		nv_node->content[j++] = last->content[i++];
	nv_node->content[j] = '\0';
	free_reserve(*reserve);
	*reserve = nv_node;
}
