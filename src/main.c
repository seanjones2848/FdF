/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:51:58 by sjones            #+#    #+#             */
/*   Updated: 2017/11/08 17:36:58 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_super *super;

	if (ac != 2)
	{
		write(1, "Put a map in please! :]\n", 24);
		return (0);
	}
	if (handle_error(av[1]))
	{
		write(1, "File error\n", 11);
		return (0);
	}
	super = init_super(open(av[1], O_RDONLY));
	put_to_center(super);
	draw_map(super);
	mlx_hook(super->win->win, 2, 0, key_press_hook, super);
	mlx_hook(super->win->win, 3, 0, key_release_hook, super);
	mlx_loop_hook(super->win->mlx, loop_hook, super);
	mlx_loop(super->win->mlx);
}
