/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:42:02 by iamoros-          #+#    #+#             */
/*   Updated: 2022/06/15 20:44:33 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(int *size, char *args)
{
	int		t;
	char	*strnull;

	t = 0;
	strnull = "(null)";
	if (args == NULL)
	{
		if (write(1, strnull, 6) != 6)
			return (*size = -1);
		*size += 6;
	}
	else
	{
		while (args[t])
		{
			if (write(1, &args[t], 1) != 1)
				return (*size = -1);
			*size += 1;
			t++;
		}
	}
	return (0);
}
