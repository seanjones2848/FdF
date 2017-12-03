/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:51:22 by sjones            #+#    #+#             */
/*   Updated: 2017/11/08 16:51:25 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawpoint(t_win *win, t_bresen *bres)
{
	bres->ny = (win->h - bres->y) - ((win->h) / 2);
	bres->nx = bres->x + ((win->w) / 2);
	color_diff(bres);
	mlx_pixel_put(win->mlx, win->win, bres->nx, bres->ny, bres->color);
}

static void	drawline_h0(t_win *win, t_bresen *bres)
{
	while (bres->x < bres->x2)
	{
		drawpoint(win, bres);
		bres->offset += bres->m;
		if (bres->offset >= bres->threshold && (bres->y += bres->adjust))
			bres->threshold += bres->thresholdinc;
		bres->x++;
	}
}

static void	drawline_h1(t_win *win, t_bresen *bres)
{
	while (bres->y < bres->y2)
	{
		drawpoint(win, bres);
		bres->offset += bres->m;
		if (bres->offset >= bres->threshold && (bres->x += bres->adjust))
			bres->threshold += bres->thresholdinc;
		bres->y++;
	}
}

/*
** handles cases where there is a hl vertical
** basicly positivise(bres, 0) but to include it
** would make stuff convoluted
*/

static void	flip(t_bresen *bres)
{
	int tmp;

	if (bres->y1 > bres->y2)
	{
		tmp = bres->y1;
		bres->y1 = bres->y2;
		bres->y2 = tmp;
		bres->y = bres->y1;
	}
}

/*
** draws verticals, pawns off steeps to drawline_h1
** and shallows to drawline_h0
*/

void		draw_line(t_point *p1, t_point *p2, t_win *win)
{
	t_bresen *bres;

	bres = init_bresen(p1, p2);
	if (bres->flip == 0)
		drawline_h0(win, bres);
	else if (bres->flip == 1)
		drawline_h1(win, bres);
	else if (bres->flip == 2)
	{
		flip(bres);
		while (bres->y < bres->y2)
		{
			drawpoint(win, bres);
			bres->y++;
		}
	}
	free(bres);
}
