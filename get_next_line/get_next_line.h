/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 07:58:21 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/01 22:23:16 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_save(char **line, char *save);
int		ft_read(int fd, char **line, char *save);
size_t	ft_strlen(char *s, char c);
void	ft_memcpy(char *dest, char *src, int flag);
char	*ft_strjoin(char *s1, char *s2, char c);
char	*ft_strchr(char *s, int c);

#endif
