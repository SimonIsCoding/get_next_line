/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:45:21 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/09 17:10:45 by simarcha         ###   ########.fr       */
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
			return (NULL);//you should call clean_and_free
		while (buf[++i] != '\0')
			stash[i] = buf[i];
		return (stash);
	}
	i = -1;
	str= ft_calloc(ft_strlen(stash) + BUFFER_SIZE + 1, sizeof(char));
	if (!(str))
		return (NULL);//call clean_and_free
	while (++i < BUFFER_SIZE)
		str[i] = stash[i];
	while (++j < BUFFER_SIZE)
		str[i + j] = buf[j];
	return (str);
}

