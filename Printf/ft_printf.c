/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:05:50 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/13 17:17:37 by iamoros-         ###   ########.fr       */
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
		}
		if (str[i] == '\0')
			return (size);
		write(1, &str[i], 1);
		size++;
		i++;
	}
	return (size);
}
/*
int	main(void)
{
	int	vr;
	int	mio;
	int	org;

	vr = -1;
	mio = 0;
	org = 0;
	mio = ft_printf("Funcion mia: %x\n", vr);
	org = printf("Funcion org: %x\n", vr);
	printf("Mi valor es: %d\nValor original es: %d\n", mio, org);
}
*/
