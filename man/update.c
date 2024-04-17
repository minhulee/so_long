/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:08:24 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:09:01 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	update_input(t_s *s)
{
	int	in;

	in = dup_input(s->player.input);
	if (in != NON)
	{
		if (in != DUP)
			s->player.dir = in;
		if (s->player.cur == IDLE)
		{
			s->player.cur = RUN;
			s->player.time = 0;
		}
	}
	else if (s->player.cur == RUN)
	{
		s->player.cur = IDLE;
		s->player.time = 0;
	}
}
