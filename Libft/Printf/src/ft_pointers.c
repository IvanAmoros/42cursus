/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:33:21 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 19:22:36 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continue_p(int *size, unsigned long long nb, char *base)
{
	int		digit;
	int		base_len;

	base_len = 16;
	if (nb == 0)
	{
		*size += 1;
		if (write(1, "0", 1) != 1)
			*size = -1;
		return (0);
	}
	digit = (nb % base_len);
	nb /= base_len;
	if (nb != 0)
		ft_continue_p(size, nb, "0123456789abcdef");
	*size += 1;
	if (write(1, &base[digit], 1) != 1)
		return (*size = -1);
	return (0);
}

int	ft_pointers(int *size, unsigned long long nb, char *base)
{
	if (!nb)
	{
		*size += 3;
		if (write(1, "0x0", 3) != 3)
			return (*size = -1);
	}
	else
	{
		*size += 2;
		if (write(1, "0x", 2) != 2)
			return (*size = -1);
		ft_continue_p(size, nb, base);
	}
	return (0);
}
