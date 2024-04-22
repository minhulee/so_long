/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:24:57 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:39 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	update_player_frame(t_s *s, t_p *p, t_a action)
{
	if (action == IDLE && p->time == 6000)
	{
		p->frame++;
		if (p->frame == PLAYER_IDLE_MAX)
			p->frame = 0;
		p->time = 0;
	}
	else if (action == RUN && p->time == 1000)
	{
		p->frame++;
		if (p->frame == PLAYER_RUN_MAX)
			p->frame = 0;
		p->time = 0;
	}
	else if (action == DEATH && p->time == 3000)
	{
		if (p->frame < PLAYER_DEATH_MAX - 1)
			p->frame++;
		else
			s->clear = TRUE;
		p->time = 0;
	}
}

void	update_map_frame(t_m *m)
{
	if (m->time == 2000)
	{
		m->frame++;
		if (m->frame == MAP_COLLECT_MAX)
			m->frame = 0;
		m->time = 0;
	}
}

void	update_zombie_frame(t_zi *zombie)
{
	if (zombie->action == IDLE && zombie->time == 2000)
	{
		zombie->frame++;
		if (zombie->frame == ZOMBIE_IDLE_MAX)
		{
			zombie->ctime++;
			zombie->frame = 0;
		}
		zombie->time = 0;
	}
	if (zombie->action == RUN && zombie->time == 1200)
	{
		zombie->frame++;
		if (zombie->frame == ZOMBIE_RUN_MAX)
		{
			zombie->ctime++;
			zombie->frame = 0;
		}
		zombie->time = 0;
	}
}

void	update_frame(t_s *s, t_p *p, t_m *m)
{	
	int	i;

	update_player_frame(s, p, p->action);
	update_map_frame(m);
	i = 0;
	while (i < s->z_num)
	{
		if (s->zombies[i].ctime == 2)
		{
			s->zombies[i].dir = rand() % DIRECTION;
			s->zombies[i].action = rand() % 2;
			s->zombies[i].ctime = 0;
			s->zombies[i].time = 0;
			s->zombies[i].frame = 0;
		}
		update_zombie_frame(&s->zombies[i]);
		i++;
	}
}

void	update_time(t_s *s)
{
	int	i;

	s->time++;
	if (!s->clear)
	{
		s->player.time++;
		s->map.time++;
		i = 0;
		while (i < s->z_num)
		{
			s->zombies[i].time++;
			i++;
		}
	}
}
