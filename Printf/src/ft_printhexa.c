/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:26:04 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 20:38:46 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(int *size, unsigned int nb, char *base)
{
	int		digit;
	int		base_len;

	base_len = 16;
	if (nb == 0)
	{
		*size += 1;
		if (write(1, "0", 1) != 1)
			return (*size = -1);
		return (0);
	}
	digit = (nb % base_len);
	nb /= base_len;
	if (nb != 0)
		if (ft_printhexa(size, nb, base) == -1)
			return (-1);
	*size += 1;
	if (write(1, &base[digit], 1) != 1)
		return (*size = -1);
	return (0);
}
