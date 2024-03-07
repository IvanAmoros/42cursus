/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:05:50 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/19 12:49:32 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkpercent(char chstr, int *size, va_list args)
{
	if (chstr == 'c')
		ft_character(size, va_arg(args, int));
	else if (chstr == 's')
		ft_printstr(size, va_arg(args, char *));
	else if (chstr == 'p')
		ft_pointers(size, va_arg(args, unsigned long long), "0123456789abcdef");
	else if (chstr == 'd')
		ft_putnbr(size, va_arg(args, int));
	else if (chstr == 'i')
		ft_putnbr(size, va_arg(args, int));
	else if (chstr == 'u')
		ft_unsputnbr(size, va_arg(args, unsigned int));
	else if (chstr == 'x')
		ft_printhexa(size, va_arg(args, unsigned int), "0123456789abcdef");
	else if (chstr == 'X')
		ft_printhexa(size, va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (chstr == '%')
		ft_printpercent(size, chstr);
}

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
