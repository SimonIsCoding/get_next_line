/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:01:04 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/09 19:29:12 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
/*
int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("line 1 : %s", get_next_line(fd));
	printf("\n");
	printf("line 2 : %s", get_next_line(fd));
//	printf("stash: %s",);
}*/

//Je veux creer une petite fonction qui contient une static char=>
//Je veux lui faire ajouter des caracteres 
//je veux les nettoyer 
//puis je veux appeler de nouveau cette variable en commencant par les caracters 
//juste apres ceux qui ont ete nettoyes

/*int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}*/
/*

void	add_chars(char *stash)
{
	char	test[BUFFER_SIZE] = " de la muerte for real";
	int		i;
	int		j;

	j = 0;
	while (stash[++j] != '\0')
		j++;
	i = 0;
	while (test[i] != '\0')
		stash[j++] = test[i++];
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\n' && i < ft_strlen(stash))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i + 1)
		line[j] = stash[j];
	 line[j] = '\0';
	 return (line);
}

void	ft_clean(char *stash)
{
	int		i;
	char	*temp;
	int		j;

	i = 0;
	while (stash[i] != '\n' && i < ft_strlen(stash))
		i++;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return ;
	j = 0;
	while (i < ft_strlen(stash))
		temp[j++] = stash[i++];
	temp[j] = '\0';
//	free(stash);
	i = -1;
	while (++i < ft_strlen(temp))
		stash[i] = temp[i];
	free(temp);
	stash[i] = '\0';
//	return (stash);
}*/
/*
int	main(void)
{
	static char	stash[99] = "This is a test\n";
	char		*line;

//	stash[15] = "This is a test";
	printf("%s\n", stash);
	add_chars(stash);
	printf("initial stash : %s\n", stash);
	line = ft_line(stash);
	printf("line          : %s", line);
	free(line);
	printf("Well freed\n");
	ft_clean(stash);
	printf("new stash     : %s\n", stash);
//	printf("Well freed");

	return (0);
}*/

int	main(void)
{
//	static char stash[BUFFER_SIZE];
	int			fd;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("First call\n");
	get_next_line(fd);
//	printf("Second call\n");
//	get_next_line(fd);
	return (0);
}




/*
int	main(void)
{
	static char stash[99] = "This is a test\n de la muerte";
	char	buf[99] = "we are in real mode";
	char	s[50] = (&stash[0] + &buf[0]); 

	printf("%s", stash);
	printf("\n\n");
	printf("%s", s);
}*/
