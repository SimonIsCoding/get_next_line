/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simarcha <simarcha@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:27:28 by simarcha          #+#    #+#             */
/*   Updated: 2024/02/11 12:52:21 by simarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
//char	*ft_strjoin(char *stash, char *buf);
char	*ft_strjoin(char *stash, char *buf, ssize_t read_result);
int		is_new_line(char *stash);
//char	*ft_strjoin(char *s1, char *s2);

#endif
