/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:42:04 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/13 19:38:08 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
void	ft_checkpercent(char chstr, int *size, va_list args);
void	ft_character(int *size, int args);
void	ft_printstr(int *size, char *args);
void	ft_putnbr(int *size, int n);
void	ft_printpercent(int *size, char chstr);
void	ft_unsigned(int *size, unsigned int nb);
char	*ft_unsitoa(unsigned int nb);
void	ft_unsputnbr(int *size, unsigned int n);
void	ft_printhexa(int *size, unsigned int nb, char *base);
void	ft_printmhexa(int *size, unsigned int nb, char *base);
void	ft_pointers(int *size, unsigned long long nb, char *base);

#endif
