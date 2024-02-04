/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:37:45 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/04 13:33:29 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "../../printf/printf_v3/printf_pushed/ft_printf.h"
#include <fcntl.h>

#define FILENAME_SIZE 1024
#define MAX_LINE 2048

int	main(void)
{
	char			s[99] = "This is a test\n de la muerte\n ";
	int				c = '\n';
	int				fd1;

    fd1 = open("text.txt", O_RDONLY);
	printf("%s\n", ft_read_the_line(s, c));
//	printf("%s\n", ft_read_the_line(s, c));


	return (0);
}

/*
int fun()
{
    static int count = 0;
    count++;
    return count;
}

int main()
{
    printf("%d ", fun());
    printf("%d ", fun());
    return 0;
}
*/
/*
int	main(void)
{
    int 	fd1;
//	int		fd2;
	size_t	read_result;
	char	buf[1024];
	size_t	nbytes;

	nbytes = 1024;
    fd1 = open("text.txt", O_RDONLY);//the open function can failed by returning -1 => you should proctect it
	if (fd1 == -1)
		return (-1);
	read_result = read(fd1, buf, nbytes);
	printf("fd1 of file %d\n", fd1);


	
//	printf("read_result, after step 1: %zu\n", read_result);
//	read_result = read(fd1, buf, nbytes);
//	get_next_line(fd1);
//	printf("read_result, after step 2: %zu\n", read_result);
//	read_result = read(fd1, buf, nbytes);
//	printf("read_result, after step 3: %zu\n", read_result);

//	fd2 = open("othertext.txt", O_RDONLY);
//	if (fd2 == -1)
//		return (-1);
//	printf("fd2 of file %d\n", fd2);

	
	return (0);
}
*/
/*
int main(void)
{
	char	s[15] = "This is a test";
	char	*cpy;

	cpy = ft_strdup(s);
	printf("%s\n", cpy);

	return (0);
}*/
/*
#include <string.h>
int	main(void)
{
	char tweet[] = "tripouille\n this is a test";
	char *mention = strrchr(tweet, '\n');
	printf("Std Lib: __%s__\n", mention);
	char *simon = ft_strrchr(tweet, '\n');
	printf("Simon's: __%s__\n", simon);

	//printf("Lib : %p\n", mention);
	//printf("Sim : %p\n", simon);

	//mention[0] = '*';
	//printf("%s\n", tweet);
}*/
