/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:25:31 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 19:02:24 by iamoros-         ###   ########.fr       */
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
