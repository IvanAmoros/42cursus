/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:46:32 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/19 17:59:01 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int argc, char *argv)
{
	if (argc != 2)
		return (1);
	if (!ft_strncmp(argv, "mandelbrot", ft_strlen(argv))
		|| !ft_strncmp(argv, "julia", ft_strlen(argv)))
		return (0);
	return (1);
}
