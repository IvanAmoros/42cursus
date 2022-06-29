/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:00:55 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/29 16:09:24 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 1

/*Este se encarga de crear u nuevo storage en base al primero, pero que no
incluya la primera linea, ya que esta ya la hemos devuelta*/
char	*clean_storage(char *storage)
{
	char	*new_storage;
	int		i;

	i = 0;
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	i++;
	new_storage = ft_substr(storage, i, ft_strlen(storage) - i);
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
	if (storage[0] == '\0')
	{
		free(storage);
		return (NULL);
	}
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	line = ft_substr(storage, 0, i);
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
//	buffer[0] = '\0';
	end = 1;
	while (!ft_strchr(buffer, '\n') && end > 0)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end == -1 || buffer[0] == '\0')
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
//	if (!storage)
//		ft_strdup("");
//	if (!storage || (storage && !ft_strchr(storage, '\n')))
	storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	if (!line || !line[0])
	{
		free(storage);
		return (NULL);
	}
	storage = clean_storage(storage);
	if (!line || !line[0])
	{
		free(storage);
		return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*test;
	int		cont;

	cont = 0;
	fd = open("test.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("La linea 1 es: %s\n", test);
	while (test[cont])
	{
		printf("%c", test[cont]);
		cont++;
	}
	printf("%c", test[cont]);
	printf("%c", test[cont + 1]);
	test = get_next_line(fd);
	printf("La linea 2 es: %s\n", test);
	test = get_next_line(fd);
	printf("La linea 3 es: %s\n", test);
	test = get_next_line(fd);
	printf("La linea 4 es: %s\n", test);
	close(fd);
	return (0);
}*/
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
