/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swirl_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:59:10 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/23 11:10:35 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	cal_swirl_pattern2(t_ss *clear, int w)
{
	if (clear->r % 2 == 0)
	{
		if (clear->loc.x < w - clear->r - 1)
			clear->loc.x++;
		else
		{
			clear->loc.y++;
			clear->r++;
			clear->t = TRUE;
		}
	}
	else
	{
		if (clear->loc.x > 0 + clear->r)
			clear->loc.x--;
		else
		{
			clear->loc.y--;
			clear->r++;
			clear->t = TRUE;
		}
	}
}

static void	cal_swirl_pattern(t_ss *clear, int w, int h)
{
	if (clear->t)
	{
		if (clear->r % 2 != 0)
		{
			if (clear->loc.y < h - clear->r)
				clear->loc.y++;
			else
			{
				clear->loc.x--;
				clear->t = FALSE;
			}
		}
		else
		{
			if (clear->loc.y > 0 + clear->r)
				clear->loc.y--;
			else
			{
				clear->loc.x++;
				clear->t = FALSE;
			}
		}
	}
	else
		cal_swirl_pattern2(clear, w);
}

static void	end_swirl(t_s *s)
{
	s->swirl.loc.x = 0;
	s->swirl.loc.y = 0;
	s->swirl.r = 0;
	s->swirl.t = FALSE;
	s->player.sp = 4;
	if (s->moved == 0)
		s->clear = FALSE;
	else
	{
		if (s->map.collected <= 0)
			mlx_string_put(s->mlx, s->win, (s->win_size.x - 160) / 2,
				s->win_size.y / 2 - 5, 0XFFFFFF, "Congratulations, You Win !!");
		else
			mlx_string_put(s->mlx, s->win, (s->win_size.x - 70) / 2,
				s->win_size.y / 2 - 10, 0XFFFFFF, "GAME OVER !!");
		s->print = TRUE;
	}
}

void	srender(t_s *s)
{
	t_ss	*swirl;
	t_v		loc;

	if (s->time == 100)
	{
		swirl = NULL;
		swirl = &s->swirl;
		loc.x = s->map.w - swirl->loc.x - 1;
		loc.y = s->map.h - swirl->loc.y;
		if (swirl->r < s->map.h / 2 + 1)
		{
			mlx_put_image_to_window(s->mlx, s->win, s->map.map[0],
				swirl->loc.x * 64, swirl->loc.y * 64);
			mlx_put_image_to_window(s->mlx, s->win, s->map.map[0],
				loc.x * 64, loc.y * 64);
			cal_swirl_pattern(swirl, s->map.w, s->map.h);
		}
		else
			end_swirl(s);
		s->time = 0;
	}
}
