/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:28:04 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/04 13:34:50 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	cpy = (char *)malloc(sizeof(*s1) * (i + 1));
	if (!cpy)
		return (NULL);
	cpy[i] = '\0';
	while (i--)
		cpy[i] = s1[i];
	return (cpy);
}

/*int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (s[--i] != '\0')
		if ((char)s[i] == (char)c)
			return ((char *)s + i);
	if ((char)c == s[i])
		return ((char *)s + i);
	return (NULL);
}

char	*ft_read_the_line(char *s, int c)
{
	char			*line;
	static ssize_t	start;
	char			buf[1024];

	start = read(3, buf, 1024);
	while (s[start] != 0)
	{
		if (s[start] == (char)c)
			break ;
		start++;
	}
	line = (char *)malloc(sizeof(*s) * (start + 1));
	if (!line)
		return (NULL);
	line[start] = 0;
	while (start--)
		line[start] = s[start];
	return (line);
}
