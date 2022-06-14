/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:33:21 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/13 20:58:54 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
/*
void ft_calc(int *size, unsigned long long nb, char *base)
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
		ft_calc(size, nb, "0123456789abcdef");
	if (nb == 0)
	{
		*size += 2;
		write(1, "0x", 1);
	}
	*size += write(1, &base[digit], 1);
}*/

void	ft_continue_p(int *size, unsigned long long nb, char *base)
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
		ft_continue_p(size, nb, "0123456789abcdef");
	*size += write(1, &base[digit], 1);
}

void	ft_pointers(int *size, unsigned long long nb, char *base)
{
	if (!nb)
	{
		*size += write(1, "0x0", 3);
	}
	else
	{
		*size += write(1, "0x", 2);
		ft_continue_p(size, nb, base);
	}
		//ft_calc(size, nb, base);
}
