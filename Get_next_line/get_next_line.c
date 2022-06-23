/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:00:55 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/23 20:45:45 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE=50


char	*get_next_line(int fd)
{
	char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE)

}

int main(void)
{
	int fd;

	fd = open("test.txt");
	get_next_line();
}
