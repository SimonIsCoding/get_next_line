/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:50:13 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/12 15:38:32 by simarcha         ###   ########.fr       */
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

char	*ft_strjoin(char *stash, char *buf, ssize_t read_result)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!stash)
	{
		str = malloc((read_result + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (buf[i] != '\0')
		{
			str[i] = buf[i];
			i++;
		}
	}
	else
	{
		str = malloc((ft_strlen(stash) + read_result + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (i < ft_strlen(stash))
		{
			str[i] = stash[i];
			i++;
		}
		while (j < (size_t)read_result)
		{
			str[i++] = buf[j++];
		}
		str[i] = '\0';
	}
	return (str);
}
