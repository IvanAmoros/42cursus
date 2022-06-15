/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:12:44 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 20:42:17 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_writer(int *size, int n)
{
	int		nb;
	int		divisor;
	char	numchar;

	nb = n;
	divisor = 1;
	while (n >= 10)
	{
		n = n / 10;
		divisor = divisor * 10;
		*size += 1;
	}
	while (divisor >= 1)
	{
		numchar = nb / divisor + '0';
		if (write(1, &numchar, 1) != 1)
		{
			*size = -1;
			return ;
		}
		nb = nb % divisor;
		divisor = divisor / 10;
	}
}

static int	ft_negative(int *size, int n)
{
	if (n == -2147483648)
	{
		*size += 11;
		if (write(1, "-2147483648", 11) != 11)
			return (*size = -1);
		return (n);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) != 1)
		{
			*size = -1;
			return (-1);
		}
		n = n * -1;
		*size += 1;
	}
	return (n);
}

void	ft_putnbr(int *size, int n)
{
	n = ft_negative(size, n);
	if (n == -2147483648 || n == -1)
		return ;
	*size += 1;
	ft_writer(size, n);
}
