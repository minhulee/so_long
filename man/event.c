/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:27:10 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:12:28 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"

static int	convert_key(int keycode)
{
	if (keycode == 123)
		return (LEFT);
	else if (keycode == 124)
		return (RIGHT);
	else if (keycode == 125)
		return (FRONT);
	else
		return (BACK);
}

int	key_press(int keycode, t_s *s)
{
	if (keycode == 15)
		game_reset(s);
	if (keycode == 53)
		destroy_game(s);
	if (keycode == 49 && s->player.target)
		collect(s);
	if (s->player.cur == DEATH)
		return (0);
	if (keycode == 2)
		s->player.cur = DEATH;
	if (123 <= keycode && keycode <= 126)
	{
		s->player.input[convert_key(keycode)] = TRUE;
		s->player.dir = convert_key(keycode);
	}
	if (keycode == 257)
		s->player.sp *= 3;
	return (0);
}

int	key_release(int keycode, t_s *s)
{
	if (s->player.cur == DEATH)
		return (0);
	if (123 <= keycode && keycode <= 126)
		s->player.input[convert_key(keycode)] = FALSE;
	if (keycode == 257)
		s->player.sp /= 3;
	return (0);
}
