/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:27:35 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/08 20:09:39 by simarcha         ###   ########.fr       */
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
		return (NULL);
	while (++i < count)
		str[i] = '\0';
	return (str);
}

int	is_line_break(char *stash)
{
	int	i;

	i = -1;
	while (stash[++i] != '\0')
		if (stash[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *stash, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (stash == NULL)
	{
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!stash)
			return (NULL);
		while (buf[++i] != '\0')
			stash[i] = buf[i];
		return (stash);
	}
	i = -1;
	str= ft_calloc(ft_strlen(stash) + BUFFER_SIZE + 1, sizeof(char));
	if (!(str))
		return (NULL);
	while (++i < BUFFER_SIZE)
		str[i] = stash[i];
	while (++j < BUFFER_SIZE)
		str[i + j] = buf[j];
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)c == (unsigned char)str[i])
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == (unsigned char)str[i])
		return ((char *)str + i);
	return (NULL);
}

char	*ft_read(int fd, char *stash)
{
	char	buf[BUFFER_SIZE];
	ssize_t	read_result;

	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result == -1 || read_result == 0)
		return (NULL);
	stash = ft_strjoin(stash, buf); 
	return (stash);
}

//ft_extract doit retourner la stash liberee de sa ligne ecrite
//doit retourner la nouvelle stash mise a jour une fois apres avoir ecrit la nouvelle ligne
char	*ft_extract(char **stash)
{
	char	*temp;
	int		i;

	i = 0;
	while (*stash[i] != '\n')//segfault
		i++;
	temp = ft_calloc(ft_strlen(*stash) - i, sizeof(char));//maybe your need + 1
	if (!temp)
		return (NULL);
	i = -1;
//	temp = ft_strchr(stash, '\n');
	while (++i < ft_strlen(temp))
		temp[i] = *stash[i];
	free(&stash);//does the free can fail ?
	return (temp);
}

//On veut juste imprimer la ligne 
char	*ft_line(char *stash)
{
	char	*line;
	int		i;
	int		total;

	i = 0;
	while (stash[i] != '\n' && i < ft_strlen(stash))//ne prends pas le \n en compte donc tu ne l'ecriras pas
		i++;
//	while (ft_strchr(stash, '\n') == NULL)
	total = i;
	line = ft_calloc(total, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < total)
		line[i] = stash[i];//lors du deuxieme appel, ta stash est vide
	return (line);
}

char	*get_next_line(int fd)
{
	static char *stash = NULL;
	char		*line;

	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	while (is_line_break(stash) == 0)
		stash = ft_read(fd, stash);//si tu veux augmenter l'espace de ta stash, il faut que tu lui envoies l'adresse => autrement elle se reinitialise a chaque fois
	line = ft_line(stash);
//	stash = ft_extract(&stash); =>ton ft_extract renvoie un segfault
	return (line);
}





































//on veut copier les caracteres de stash dans line jusqua le '\n'
/*char	*ft_extract(char *stash)
{
	int		i;
	char	*line;
	char	*temp;
	int		j;

	i = -1;
	j = -1;
	line = (char *)ft_calloc(ft_strlen(stash), sizeof(char));
	if (!line)
		return (NULL);
	while (++i < ft_strlen(stash) && stash[i] != '\n')
		line[i] = stash[i];
	temp = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return (NULL);
	while (i < ft_strlen(stash))//try to see what i++ gives
		temp[++j] = stash[++i];
	free(stash);
	stash = (char *)malloc(sizeof(char) * (ft_strlen(temp)));
	if (!stash)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(temp))
		stash[i] = temp[i];
	return (line);
}*/
