/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:50:13 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/12 19:02:12 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_new_line(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	*ft_calloc(size_t count, size_t size)
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

char	*ft_strjoin(char *stash, char *buf, ssize_t read_result)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!stash)
	{
		str = ft_calloc((read_result + 1), sizeof(char));
		if (!str)
			return (NULL);
		while (buf[++i] != '\0')
			str[i] = buf[i];
		return (str);
	}
	str = ft_calloc((ft_strlen(stash) + read_result + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (++i < ft_strlen(stash))
		str[i] = stash[i];
	while (j < (size_t)read_result)
		str[i++] = buf[j++];
	free(stash);
	return (str);
}
