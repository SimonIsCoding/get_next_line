/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:40:23 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/09 17:56:50 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//at the beginning, the stash is empty => we need to add chars in it
//we need a function to fill the stash

char	*ft_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (stash[i] != '\n' && i < ft_strlen(stash))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
//		return (clean_and_free(line));
		return (NULL);
	while (++j < i + 1)
		line[j] = stash[j];
	line[j] = '\0';
	return (line);
}//once you use this function in gnl, you should free the line in your main

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
	int		i;
	int		j;
	int		len_line;

	i = 0;
	while (stash[i] != '\n' && i < ft_strlen(stash))
		i++;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 2));
	if (!temp)
//		return (clean_and_free(temp));
		return (NULL);
	len_line = i + 2;
	j = 0;
	i++;
	while (j < ft_strlen(stash) - len_line)
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	i = -1;
	while (++i < j)
		stash[i] = temp[i];
	free(temp);
	stash[i] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	ssize_t		read_result;
	char		buf[BUFFER_SIZE];

	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result <= 0)
		return (NULL);
	stash = ft_strjoin(stash, buf);
	printf("Initial stash : %s\n", stash);
	line = ft_line(stash);
	printf("Line          : %s\n", line);
	stash = clean_stash(stash);
	printf("New free stash: %s", stash);
	return (line);
}
