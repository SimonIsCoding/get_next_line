/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:37:50 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/20 10:58:08 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//we use substr to grab what was in stash and fill the line
static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	j = ft_strlen(s + start);
	if (len > j)
		len = j;
	substr = (char *)malloc(len + 1);
	if (!s || !substr)
		return (NULL);
	j = 0;
	while (i < ft_strlen(s) && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}

//this function helps us to complete the line up to the '\n' character is found 
static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

static char	*clean_stash_and_line(char *line_buf)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line_buf[i] != '\n' && line_buf[i] != '\0')
		i++;
	if (line_buf[i] == 0 || line_buf[1] == 0)
		return (NULL);
	stash = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - i);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line_buf[i + 1] = 0;
	return (stash);
}

static char	*complete_stash_and_line(int fd, char *stash, char *buf)
{
	ssize_t	read_result;
	char	*tmp;

	read_result = 1;
	while (read_result > 0)
	{
		read_result = read(fd, buf, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (read_result == 0)
			break ;
		buf[read_result] = 0;
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), free(buf), stash = NULL, buf = NULL, NULL);
	if (!buf)
		return (NULL);
	line = complete_stash_and_line(fd, stash, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stash = clean_stash_and_line(line);
	return (line);
}
