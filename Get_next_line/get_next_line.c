/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:00:55 by iamoros-          #+#    #+#             */
/*   Updated: 2022/07/06 14:24:00 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_storage(char *storage)
{
	char	*new_storage;
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!new_storage)
		return (NULL);
	i++;
	while (storage[i])
		new_storage[p++] = storage[i++];
	new_storage[p] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_line(char *storage)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] != '\n' && storage[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*fill_storage(int fd, char *storage)
{
	char	*buffer;
	int		end;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	end = 1;
	while (!ft_strchr(buffer, '\n') && end != 0)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[end] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_calloc(1, 1);
	storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = clean_storage(storage);
	return (line);
}
