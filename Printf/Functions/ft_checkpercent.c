/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:25:31 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/13 20:28:45 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_checkpercent(char chstr, int *size, va_list args)
{
	if (chstr == 'c')
		ft_character(size, va_arg(args, int));
	else if (chstr == 's')
		ft_printstr(size, va_arg(args, char *));
	else if (chstr == 'p') //puntero void * en hexadecimal
		ft_pointers(size, va_arg(args, unsigned long long), "0123456789abcdef");
	else if (chstr == 'd')
		ft_putnbr(size, va_arg(args, int));
	else if (chstr == 'i')
		ft_putnbr(size, va_arg(args, int));
	else if (chstr == 'u')
		ft_unsputnbr(size, va_arg(args, unsigned int));
	else if (chstr == 'x') //imprimir un numero hexadecimal de base 16 en minusculas
		ft_printhexa(size, va_arg(args, unsigned int), "0123456789abcdef");
	else if (chstr == 'X') //imprimir unn numero hexadecimal de base 16 mayusculas
		ft_printmhexa(size, va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (chstr == '%')
		ft_printpercent(size, chstr);
}
