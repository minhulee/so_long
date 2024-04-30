/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:27:10 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/23 12:59:47 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (keycode == 53)
		end(s);
	if (keycode == 15 && (!s->clear || s->print))
		restart(s);
	if (keycode == 49 && s->player.target)
		collect(s);
	if (s->player.action == DEATH)
		return (0);
	if (keycode == 2)
		s->player.action = DEATH;
	if (123 <= keycode && keycode <= 126)
	{
		s->player.input[convert_key(keycode)] = TRUE;
		s->player.dir = convert_key(keycode);
	}
	if (keycode == 257)
		s->player.sp = 12;
	return (0);
}

int	key_release(int keycode, t_s *s)
{
	if (123 <= keycode && keycode <= 126)
		s->player.input[convert_key(keycode)] = FALSE;
	if (keycode == 257)
		s->player.sp = 4;
	return (0);
}

static int	dup_input(int input[4])
{
	int	key;
	int	in;

	key = FRONT;
	in = NON;
	while (key <= BACK)
	{
		if (input[key] == TRUE)
		{
			if (in == NON)
				in = key;
			else
				return (DUP);
		}
		key++;
	}
	if (in != NON)
		return (in);
	return (NON);
}

void	input(t_s *s)
{
	int	in;

	in = dup_input(s->player.input);
	if (in != NON)
	{
		if (in != DUP)
			s->player.dir = in;
		if (s->player.action == IDLE)
		{
			s->player.action = RUN;
			s->player.frame = 0;
			s->player.time = 0;
		}
	}
	else if (s->player.action == RUN)
	{
		s->player.action = IDLE;
		s->player.frame = 0;
		s->player.time = 0;
	}
}
