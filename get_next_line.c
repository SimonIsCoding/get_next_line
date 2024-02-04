/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:28:01 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/04 10:53:44 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//the aim function is to save the characters read into a stash
//we will create a malloc with the size of the line => how to know the size ? do we use a counter ?
//one way can be to do a malloc, save the characters
//then we will save what we read into the malloc

char	*ft_read(char *storage, int fd)
{
	char	*line;
	ssize_t ctr_read;
	void	*buf;
	size_t	nbytes;

	ctr_read = read(fd, buf, nbytes);
	line = (char *)malloc(sizeof(*storage) * (ctr_read + 1));
	while (ft_strchr(storage, '\n') != NULL)
	{
		
	}
}

char	*ft_extract(char *storage)//here we copy the strings read before to show them
{

}

char	*ft_update_storage(char *storage)
{
	if (*storage == '\n')
		//update storage
}


{
	static char *storage = NULL;
	char		*line;

	storage = ft_read(storage, fd);
	line	= ft_extract(storage);
	storage	= ft_update_storage(storage);

	return (line);
}


char *get_next_line(int fd)
{
	static char *stash;
	char 		*buffer;
}
