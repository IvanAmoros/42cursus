/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:25:37 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/13 23:10:45 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_win	tutorial;

	tutorial = new_program(2500, 1200, "Fractol");
	if (!tutorial.mlx_ptr || !tutorial.win_ptr)
		return (1);
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}
