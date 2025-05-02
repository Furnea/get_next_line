/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfurnea <rfurnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:20:33 by rfurnea           #+#    #+#             */
/*   Updated: 2025/05/02 19:23:45 by rfurnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	init_data(char **leftover, char **buffer)
{
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buffer)
		return (ERR_ALLOC);
	if (!*leftover)
	{
		*leftover = malloc(1);
		if (!*leftover)
		{
			free(*buffer);
			return (ERR_ALLOC);
		}
		(*leftover)[0] = '\0';
	}
	return (ERR_OK);
}

char	*split_leftover(char **leftover)
{
	char	*line;
	char	*rest;
	char	*nl;
	size_t	len;

	nl = gnl_strchr(*leftover, '\n');
	if (nl)
	{
		len = nl - *leftover + 1;
		line = gnl_substr(*leftover, 0, len);
		rest = gnl_substr(*leftover, len, gnl_strlen(*leftover) - len);
		free(*leftover);
		*leftover = rest;
		return (line);
	}
	if (gnl_strlen(*leftover) > 0)
	{
		line = gnl_substr(*leftover, 0, gnl_strlen(*leftover));
		free(*leftover);
		*leftover = NULL;
		return (line);
	}
	free(*leftover);
	*leftover = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	ssize_t		bytes_read;
	char		*aux_ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (init_data(&leftover, &buffer) != ERR_OK)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(leftover, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
		aux_ptr = gnl_strjoin(leftover, buffer);
		free(leftover);
		leftover = aux_ptr;
	}
	free(buffer);
	if (bytes_read < 0)
		return (free(leftover), leftover = NULL, NULL);
	return (split_leftover(&leftover));
}
