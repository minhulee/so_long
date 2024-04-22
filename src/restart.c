/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:38:29 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 15:47:39 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_time_frame(t_s *s, t_p *p, t_m *m, t_zi *zi)
{
	int	i;

	s->time = 0;
	p->time = 0;
	m->time = 0;
	p->frame = 0;
	m->frame = 0;
	i = 0;
	while (i < s->z_num)
	{
		zi[i].time = 0;
		zi[i].frame = 0;
		zi[i].action = rand() % 2;
		zi[i].target = NULL;
		i++;
	}
}

static void	reset_map_data(t_m *m, t_md **md)
{
	int	h;
	int	w;

	h = 1;
	while (h < m->h - 1)
	{
		w = 1;
		while (w < m->w - 1)
		{
			md[h][w].visited = FALSE;
			w++;
		}
		h++;
	}
	m->collected = m->max_collected;
}

static void	reset_zombie_loc(t_s *s, t_zi *zombies)
{
	int	i;

	i = 0;
	while (i < s->z_num)
	{
		zombies[i].loc.x = zombies[i].start.x * 64;
		zombies[i].loc.y = zombies[i].start.y * 64;
		i++;
	}
}

void	restart(t_s *s)
{
	reset_map_data(&s->map, s->map.md);
	init_swirl(&s->swirl);
	init_time_frame(s, &s->player, &s->map, s->zombies);
	reset_zombie_loc(s, s->zombies);
	s->moved = 0;
	if (s->print)
		s->clear = FALSE;
	else
		s->clear = TRUE;
	s->print = FALSE;
	s->player.action = IDLE;
	s->player.loc.x = s->map.start.x * 64;
	s->player.loc.y = s->map.start.y * 64 - 20;
	s->player.target = NULL;
	ft_printf("restart...\nMOVE : %d\n", s->moved);
}
