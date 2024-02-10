/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:45:21 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/10 19:36:19 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = -1;
	str = (void *)malloc(size * count);
	if (!(str))
		return (NULL);//call clean_and_free
	while (++i < count)
		str[i] = '\0';
	return (str);
}

//Maybe Wrong
char	*ft_strjoin(char *stash, char *buf, ssize_t read_result)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	//on va creer un compteur qui va compter jusqu'a ce que buf soit finit
	//ce compteur va nous permettre de savoir combien d'espace de stockage a-t-on
	//besoin pour creer notre malloc
	if (stash == NULL)
	{
		stash = ft_calloc(read_result + 1, sizeof(char));//il me semble que tu as besoin du +1 pour metre le charactere nul de fin 
		if (!stash)
			return (NULL);//you should call clean_and_free
		while ((int)++i < read_result)
			stash[i] = buf[i];
		return (stash);
	}
	str = ft_calloc(ft_strlen(stash) + read_result + 1, sizeof(char));//le +1 pour le character null est deja integre
	if (!(str))
		return (NULL);//call clean_and_free
	while ((int)++i < ft_strlen(stash))
		str[i] = stash[i];
	while ((ssize_t)++j < read_result)
		str[i + j] = buf[j];
	return (str);
}

//il y a un probleme sur la place que tu alloues dans ton buffer
//si dans le fichier il n'y a qu'1 caractere mais que ton BUFFER_SIZE = 8,
//il faut que tu alloues 1 + 1 = 2 bytes de memoire => Sinon LEAK
//il faut que tu trouves une maniere de savoir qu'il n'y a qu'un caractere
//
