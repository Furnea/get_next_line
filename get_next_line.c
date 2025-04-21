#include "get_next_line.h"

char	*extract_line(char **remainder)
{
	char	*line;
	char	*new_remainder;
	size_t	i = 0;

	if (!*remainder || **remainder == '\0')
		return (NULL);
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *remainder, i);
	line[i] = '\0';

	new_remainder = ft_strdup(*remainder + i);
	free(*remainder);
	*remainder = new_remainder;

	return (line);
}

char	*get_next_line(int fd)
{
	static char	*aux_str;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		aux_str = ft_strjoin(aux_str, buffer);
		if (ft_strchr(aux_str, '\n'))
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if(bytes_read < 0)
		return (free(aux_str), NULL);
	line = extract_line(&aux_str);
	if (!line)
	{
		free(aux_str);
		aux_str = NULL;
	}
	return (line);
}
