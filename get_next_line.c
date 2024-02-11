/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:40:23 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/11 14:51:20 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//at the beginning, the stash is empty => we need to add chars in it
//we need a function to fill the stash

char	*write_line(char *stash)//il est possible que ta fonction alloues +1 en trop => verifie bien l'espace
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (stash[i] != '\n' && i < ft_strlen(stash))
		i++;	
	line = ft_calloc((i + 1 + 1), sizeof(char));
	if (!line)
//		return (clean_and_free(line));
		return (NULL);
	while (++j < i + 1)
		line[j] = stash[j];
	return (line);
}

//si le malloc fail, on veut free tous les emplacement et retourner NULL
/*char	*clean_and_free(char *s)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(s))
	{
		free(s[i]);
		s[i] = NULL;
	}
	return (NULL);
}*/

char	*clean_stash(char *stash)
{
	char	*temp;
	size_t	i;
	size_t	j;
	size_t	len_line;

	i = 0;
	while (stash[i] != '\n' && i < ft_strlen(stash))//attention a comment tu comptes ton i =>je ne mettrais que i < ft_strlen(stash) car tu free a la fin
		i++;
	temp = ft_calloc((i + 1), sizeof(char));
	if (!temp)
//		return (clean_and_free(temp));
		return (NULL);
	len_line = i;// + 1;//est-ce que le fait de mettre +1 retire le dernier caractere NULL ?
	j = 0;
	while (j < ft_strlen(stash) - len_line)
		temp[j++] = stash[++i];//on fait ++i car le i est a la position du caractere '\n'. Donc on l'augmente pour ne pas le prendre
	i = -1;
	while (++i < j)
		stash[i] = temp[i];
	free(temp);
	stash[i] = '\0';
	return (stash);
}

//we have to call the function read (2) many times in order to stock the other letter in our stash
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	ssize_t		read_result;
	void		*buf;

	buf = malloc(BUFFER_SIZE * (sizeof(char)));
	if (!buf)
		return (NULL);
	read_result = read(fd, buf, BUFFER_SIZE); 
	if ((read_result <= 0 && stash == NULL) ||
			(read_result <= 0 && ft_strlen(stash) == 0))//stash[0] == '\0'))//ft_strlen(stash) == 0
		return (NULL);
	stash = ft_strjoin(stash, buf, read_result);
	if (!stash)
		return (NULL);
	while (is_new_line(stash) == 0 && read(fd, buf, BUFFER_SIZE) > 0)
	{
		stash = ft_strjoin(stash, buf, read_result);//Attention a la taille de read_result
		if (!stash)
			return (NULL);
	}
//	printf("Initial stash : %s\n", stash);
	line = write_line(stash);
	if (!line)
		return (NULL);//free stash as well
//	printf("Line          : %s\n", line);
	stash = clean_stash(stash);
//	if (!stash)
//		return (NULL);
//	printf("New free stash: %s", stash);*/
	free(buf);
	if (ft_strlen(stash) == 0 && read(fd, buf, BUFFER_SIZE) <= 0)
		free(stash);
	return (line);
}

//mon probleme est que ma stash peut contenir des caracteres alors que le resultat de read est <= 0
//comment gerer ceci
