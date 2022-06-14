/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:42:02 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/09 02:02:22 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printstr(int *size, char *args)
{
	int		t;
	char	*strnull;

	t = 0;
	strnull = "(null)";
	if (args == NULL)
	{
		write(1, strnull, 6);
		*size += 6;
	}
	else
	{
		while (args[t])
		{
			write(1, &args[t], 1);
			*size += 1;
			t++;
		}
	}
}
