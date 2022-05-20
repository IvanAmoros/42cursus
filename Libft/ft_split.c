/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:28:25 by iamoros-          #+#    #+#             */
/*   Updated: 2022/05/20 04:50:44 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}
*/
void	ft_free(char **str, size_t x)
{
	while (x >= 0)
	{
		free(str[x]);
		x--;
	}
	free(str);
}

static size_t	c_words(char const *s, char c)
{
	int		i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static size_t	c_start(char const *s, char c, size_t start)
{
	while (s[start] == c)
		start++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	size_t	x;
	size_t	start;
	size_t	end;
	char	**str;

	start = 0;
	x = 0;
	w = c_words(s, c);
	str = (char **)malloc(w * sizeof(char *) + 1);
	if (!str)
		return (0);
	while (x < w)
	{
		start = c_start(s, c, start);
		end = 0;
		while (s[start] != c && s[start] != '\0')
		{
			end++;
			start++;
		}
		str[x] = ft_substr(s, start - end, end);
		if (!str[x])
		{
			ft_free(str, x);
			return (NULL);
		}
//		printf("Str len: %zu\n", ft_strlen(str[x]));
		x++;
	}
	str[x] = NULL;
	return (str);
}
/*
int	main(void)
{
	int	i;
	char **tabstr;

	i = 0;
    if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
        ft_print_result("NULL");
    else
    {
        while (tabstr[i] != NULL)
        {
            ft_print_result(tabstr[i]);
            write(1, "\n", 1);
            i++;
        }
    }
}
*/
