/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:32:40 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/19 12:39:45 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	end = 1;
	while (!ft_strchr(storage, '\n') && end != 0)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		if (end > 0)
		{
			buffer[end] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_calloc(1, 1);
	storage[fd] = fill_storage(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = get_line(storage[fd]);
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
