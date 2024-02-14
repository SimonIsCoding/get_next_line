/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:04:46 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/13 18:32:37 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	endline_counter(char *stash)
{
	size_t	i;

	i = -1;
	while (stash[++i] != '\0')
	{
		if (stash[i] == '\n')
		{
			i++;
			return (i);
		}
	}
	return (i);
}

static char	*complete_line(char *stash)
{
	size_t	i;
	char	*line;
	size_t	len_line;

	len_line = endline_counter(stash);
	line = malloc((len_line + 1) * sizeof(*stash));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len_line)
		line[i] = stash[i];
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*temp;
	size_t	i;
	size_t	len_line;

	len_line = endline_counter(stash);
	i = -1;
	temp = malloc((ft_strlen(stash) - len_line + 1) * sizeof(*stash));
	if (!temp)
		return (NULL);
	while (++i < ft_strlen(stash) - len_line + 1)
		temp[i] = stash[len_line + i];
	temp[i] = '\0';
	free(stash);
	stash = malloc(ft_strlen(temp) * sizeof(*stash));
	if (!stash)
		return (NULL);
	i = -1;
	while (temp[++i] != '\0')
		stash[i] = temp[i];
	stash[i] = '\0';
	free(temp);
	return (stash);
}
/*
char	*gnl_helper(int fd, char *stash, void *buf, ssize_t read_result)
{
	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result <= 0 && (stash == NULL || *stash == '\0'))
	{
		free(buf);
		return (NULL);
	}
	stash = ft_strjoin(stash, buf, read_result);
	if (!stash)
	{
		free(buf);
		return (NULL);
	}
	return (stash);
}*/

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;
	ssize_t			read_result;
	void			*buf;

	buf = malloc(BUFFER_SIZE * (sizeof(*buf)));
	if (!buf)
		return (NULL);
	read_result = 1; 
	while (!stash || (is_new_line(stash) == 0 && read_result > 0))
	{
		read_result = read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf, read_result);
	}
	if (read_result <= 0 && (stash == NULL || *stash == '\0'))
	{
		free(buf);
		return (NULL);
	}
	if (!stash)
	{
		free(buf);
		return (NULL);
	}
//	stash = gnl_helper(fd, stash, buf, read_result);
	free(buf);
	line = complete_line(stash);
	if (!line)
		return (NULL);
	stash = clean_stash(stash);
	if (!stash)
		return (NULL);
	return (line);
}
