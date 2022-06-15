/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:05:50 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 18:33:36 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	int		size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] == '%')
		{
			i += 2;
			ft_checkpercent(str[i - 1], &size, args);
			if (size == -1)
				return (-1);
		}
		if (str[i] == '\0')
			return (size);
		if (write(1, &str[i], 1) != 1)
			return (-1);
		size++;
		i++;
	}
	return (size);
}
