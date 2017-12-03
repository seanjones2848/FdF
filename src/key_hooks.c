/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:51:46 by sjones            #+#    #+#             */
/*   Updated: 2017/11/08 16:51:48 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_release_help(int key, t_super *s)
{
	if (key == KEY_1)
		s->keys->n1 = false;
	if (key == KEY_2)
		s->keys->n2 = false;
	if (key == KEY_3)
		s->keys->n3 = false;
	if (key == KEY_4)
		s->keys->n4 = false;
	if (key == KEY_5)
		s->keys->n5 = false;
	if (key == KEY_6)
		s->keys->n6 = false;
}

int			key_release_hook(int key, t_super *s)
{
	if (key == KEY_ESCAPE)
		s->keys->esc = false;
	if (key == KEY_P)
		s->keys->p = false;
	if (key == KEY_UP)
		s->keys->up = false;
	if (key == KEY_DOWN)
		s->keys->down = false;
	if (key == KEY_RIGHT)
		s->keys->right = false;
	if (key == KEY_LEFT)
		s->keys->left = false;
	if (key == KEY_PAD_ADD || key == KEY_GREATER_THAN)
		s->keys->add = false;
	if (key == KEY_PAD_SUB || key == KEY_LESS_THAN)
		s->keys->sub = false;
	key_release_help(key, s);
	return (0);
}

static void	key_press_help(int key, t_super *s)
{
	if (key == KEY_1)
		s->keys->n1 = true;
	if (key == KEY_2)
		s->keys->n2 = true;
	if (key == KEY_3)
		s->keys->n3 = true;
	if (key == KEY_4)
		s->keys->n4 = true;
	if (key == KEY_5)
		s->keys->n5 = true;
	if (key == KEY_6)
		s->keys->n6 = true;
}

int			key_press_hook(int key, t_super *s)
{
	if (key == KEY_ESCAPE)
		s->keys->esc = true;
	if (key == KEY_P)
		s->keys->p = true;
	if (key == KEY_UP)
		s->keys->up = true;
	if (key == KEY_DOWN)
		s->keys->down = true;
	if (key == KEY_RIGHT)
		s->keys->right = true;
	if (key == KEY_LEFT)
		s->keys->left = true;
	if (key == KEY_PAD_ADD || key == KEY_GREATER_THAN)
		s->keys->add = true;
	if (key == KEY_PAD_SUB || key == KEY_LESS_THAN)
		s->keys->sub = true;
	key_press_help(key, s);
	return (0);
}
