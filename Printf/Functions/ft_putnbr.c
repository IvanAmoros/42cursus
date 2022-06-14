/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:12:44 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/09 02:32:46 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_negative(int *size, int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*size += 11;
		return (n);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		*size += 1;
	}
	return (n);
}

void	ft_putnbr(int *size, int n)
{
	char	numchar;
	int		count;
	int		divisor;
	int		nb;

	count = 0;
	divisor = 1;
	n = ft_negative(size, n);
	if (n == -2147483648)
		return ;
	nb = n;
	*size += 1;
	while (n >= 10)
	{
		n = n / 10;
		divisor = divisor * 10;
		*size += 1;
	}
	while (divisor >= 1)
	{
		numchar = nb / divisor + '0';
		write(1, &numchar, 1);
		nb = nb % divisor;
		divisor = divisor / 10;
	}
}
