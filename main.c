/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:15:57 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/20 10:57:57 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/*int	main(void)
{
	int		fd;
	int		read_result;
	char	*buf;
	size_t	len_buf;
	int		i;

	buf = malloc(BUFFER_SIZE * sizeof(*buf));
	if (!buf)
		return (1);
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result <= 0)
		return (1);
	len_buf = ft_strlen(buf);
	i = -1;
	while (buf[++i] != '\0')
		printf("letter position %d: __%c__\n", i, (char)buf[i]);
	printf("%zu\n", len_buf);
	return (0);
}*/

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text.txt", O_RDWR);
	if (fd < 0)
		return (1);
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || i > 80)
			break ;
		printf("line %d : %s", i++, line);
		free(line);
	}
	printf("line %d : %s", i++, line);
	close(fd);
	return (0);
}
/*
static int	shift()
{
	int i = 0;
	i++;
	return (i);
}
int	main(void)
{
	shift();
	printf("first call : %d\n", shift());
	shift();
	printf("second call : %d", shift());
	return (0);
}*/
