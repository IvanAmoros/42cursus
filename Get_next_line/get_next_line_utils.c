/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:22:14 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/29 11:37:32 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s;
	char	*str;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((s + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i < s)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((unsigned int)ft_strlen(s) < start)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (0);
		*str = '\0';
		return (str);
	}
	if (len > ft_strlen(&s[start]))
		len = (size_t)ft_strlen(&s[start]);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		p;

	p = 0;
	while (s1[p])
		p++;
	str = (char *)malloc((p + 1) * sizeof(char));
	if (!str)
		return (0);
	p = 0;
	while (s1[p])
	{
		str[p] = s1[p];
		p++;
	}
	str[p] = '\0';
	return (str);
}
