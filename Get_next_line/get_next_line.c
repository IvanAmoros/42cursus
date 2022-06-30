/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:00:55 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/30 17:22:22 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5

/*Este se encarga de crear u nuevo storage en base al primero, pero que no
incluya la primera linea, ya que esta ya la hemos devuelta*/
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

/*Este se encarga de leer la primera linea dentro de storage (linea acaba
en \n o \0 y devolver un malloc de ella)*/
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

//este se encarga de llenar storage hasta encontrar un \n o \0
char	*fill_storage(int fd, char *storage)
{
	char	*buffer;
	int		end;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	end = 1;
	while (!ft_strchr(buffer, '\n') && end != 0)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end == -1)
		{
			free(buffer);
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
	storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = clean_storage(storage);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*test;

	fd = open("test.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("La linea 1 es: %s", test);
	test = get_next_line(fd);
	printf("La linea 2 es: %s", test);
	test = get_next_line(fd);
	printf("La linea 3 es: %s", test);
	test = get_next_line(fd);
	printf("La linea 4 es: %s", test);
	test = get_next_line(fd);
	printf("La linea 5 es: %s", test);
	test = get_next_line(fd);
	printf("La linea 6 es: %s", test);
	close(fd);
	return (0);
}
/*
archivo original = kjkufduih fsu udfi ufisdu is fdsih\n iusfuh uifhdsiuhfiudiu
storage  = kjkhdfksf hsj hkdjsh jks hkjsh kdfsh kj\n sdhfdhs 
linea =  kbdsabsd j asdb jhabbhdb jjadhsb daj\n
storage =  sdhfdhs


suma_uno()
{
	static num = 1;
	num = num + 1;
}

main()
{
	syma_uno(); //num vale 2
	suma_uno(); //num vale 3
}*/
