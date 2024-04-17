/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swirl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:59:10 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:59:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cal_swirl_pattern2(t_e *clear, int w)
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

static void	cal_swirl_pattern(t_e *clear, int w, int h)
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
	s->clear.loc.x = 0;
	s->clear.loc.y = 0;
	s->clear.r = 0;
	s->clear.t = FALSE;
	if (s->moved == 0)
		s->clear.c = FALSE;
	else
	{
		if (s->map.collected != 0)
			mlx_string_put(s->mlx, s->win, (s->win_size.x - 160) / 2,
			s->win_size.y / 2 - 5, 0XFFFFFF, "Congratulations, You Win !!");
		else
			mlx_string_put(s->mlx, s->win, (s->win_size.x - 70) / 2,
				s->win_size.y / 2 - 10, 0XFFFFFF, "GAME OVER !!");
		s->print = TRUE;
	}
}

void	render_swirl(t_s *s)
{
	t_e	*clear;
	t_v	loc;

	clear = NULL;
	if (s->time == 50)
	{
		clear = &s->clear;
		loc.x = s->map.w - clear->loc.x - 1;
		loc.y = s->map.h - clear->loc.y;
		if (clear->r < s->map.h / 2 + 1)
		{
			mlx_put_image_to_window(s->mlx, s->win, s->map.m_img[0],
				clear->loc.x * 64, clear->loc.y * 64);
			mlx_put_image_to_window(s->mlx, s->win, s->map.m_img[0],
				loc.x * 64, loc.y * 64);
			cal_swirl_pattern(clear, s->map.w, s->map.h);
		}
		else
			end_swirl(s);
		s->time = 0;
	}
}
