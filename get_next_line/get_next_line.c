/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 07:56:51 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/01 22:55:46 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_save(char **line, char *save)
{
	char	*tmp;

	if (!ft_strchr(save, '\n'))
	{
		*line = ft_strjoin(*line, save, '\0');
		save[0] = '\0';
	}
	else
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (0);
		*line = ft_strjoin(*line, save, '\n');
		ft_memcpy(tmp, save, 1);
		if (tmp[0] == '\0' && save[0] != '\n')
			tmp[0] = '\n';
		ft_memcpy(save, tmp, 0);
		free(tmp);
	}
	return (1);
}

int	ft_read(int fd, char **line, char *save)
{
	char	*buff;
	int		bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes <= 0 && !save[0] && !*line[0])
		return (free(buff), 0);
	buff[bytes] = '\0';
	while (bytes > 0 && !ft_strchr(buff, '\n'))
	{
		*line = ft_strjoin(*line, buff, '\0');
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = '\0';
	}
	if (ft_strchr(buff, '\n'))
	{
		*line = ft_strjoin(*line, buff, '\n');
		ft_memcpy(save, buff, 1);
	}
	return (free(buff), 1);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	*line = '\0';
	if (save[0])
		if (!ft_save(&line, save))
			return (NULL);
	if (!save[0])
	{
		if (!ft_read(fd, &line, save))
			return (free(line), NULL);
	}
	return (line);
}
