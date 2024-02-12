/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:04:46 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/12 17:05:29 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*complete_line(char *stash)
{
	size_t	i;
	char	*line;
	size_t	len_line;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	len_line = i;
	line = malloc((len_line + 1) * sizeof(*stash));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len_line)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*temp;
	size_t	i;
	size_t	len_line;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	len_line = i;
	i = 0;
	temp = malloc((ft_strlen(stash) - len_line + 1) * sizeof(*stash));
	if (!temp)
		return (NULL);
	while (i < ft_strlen(stash) - len_line + 1)
	{
		temp[i] = stash[len_line + i];
		i++;
	}
	temp[i] = '\0';
	free(stash);
	stash = malloc(ft_strlen(temp) * sizeof(*stash));
	if (!stash)
		return (NULL);
	i = 0;
	while (temp[i] != '\0')
	{
		stash[i] = temp[i];
		i++;
	}
	stash[i] = '\0';
	free(temp);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = (char *)'\0';
	char		*line;
	ssize_t		read_result;
	void		*buf;

	buf = malloc(BUFFER_SIZE * (sizeof(*buf)));
	if (!buf)
		return (NULL);
	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result <= 0 && (stash == NULL || *stash == '\0'))
		return (NULL);
	stash = ft_strjoin(stash, buf, read_result);
	if (!stash)
		return (NULL);
	while (is_new_line(stash) == 0 && read_result > 0)
	{
		read_result = read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf, read_result);
	}
	line = complete_line(stash);
	if (!line)
		return (NULL);
	stash = clean_stash(stash);
	if (!stash)
		return (NULL);
	free(buf);
//	if (read_result <= 0 && *stash == '\0')
//		free(stash);
	return (line);
}
