/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:26:04 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/13 16:09:09 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printhexa(int *size, unsigned int nb, char *base)
{
	int		digit;
	int		base_len;

	base_len = 16;
	if(nb == 0)
	{
		*size += write(1, "0", 1);
		return ;
	}
	digit = (nb % base_len);
	nb /= base_len;
	if(nb != 0)
		ft_printhexa(size, nb, "0123456789abcdef");
	*size += write(1, &base[digit], 1);
}
