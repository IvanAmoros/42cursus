/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:41:14 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 19:52:05 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsputnbr(int *size, unsigned int n)
{
	char			numchar;
	int				divisor;
	unsigned int	nb;

	divisor = 1;
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
		if (write(1, &numchar, 1) != 1)
			return (*size = -1);
		nb = nb % divisor;
		divisor = divisor / 10;
	}
	return (0);
}
