/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:26:32 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:33:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"

void	*load_action(t_p *p)
{
	if (p == NULL)
		return (NULL);
	else
	{
		if (p->cur == IDLE)
			return (p->idle[p->dir]->img);
		else if (p->cur == RUN)
			return (p->run[p->dir]->img);
		else
			return (p->death[p->dir]->img);
	}
}

void	update_player(t_s *s, t_p *p)
{
	if (s->player.cur == IDLE)
	{
		if (s->player.time == 6000)
		{
			p->idle[p->dir] = p->idle[p->dir]->next;
			p->time = 0;
		}
	}
	if (s->player.cur == RUN)
	{
		if (s->player.time == 1000)
		{
			p->run[p->dir] = p->run[p->dir]->next;
			p->time = 0;
		}
	}
	if (s->player.cur == DEATH && p->deathd < P_DEATH_MAX - 1)
	{
		if (s->player.time == 3000)
		{
			p->death[p->dir] = p->death[p->dir]->next;
			p->time = 0;
			p->deathd++;
		}
	}
}

static void	init_player(t_s *s, t_p *p)
{
	int	i;

	p->cur = IDLE;
	p->dir = FRONT;
	p->time = 0;
	p->deathd = 0;
	p->sp = 4;
	p->target = NULL;
	i = 0;
	while (i < 4)
	{
		p->idle[i] = NULL;
		p->run[i] = NULL;
		p->death[i] = NULL;
		p->input[i] = FALSE;
		i++;
	}
	p->loc.x = s->map.start.x * 64;
	p->loc.y = s->map.start.y * 64 - 20;
}

t_b	load_player(t_s *s, t_p *p)
{
	init_player(s, p);
	if (load_xpm_dir(s, p->idle, P_IDLE_MAX, P_PATH) == FAIL)
		return (FAIL);
	if (load_xpm_dir(s, p->run, P_RUN_MAX, P_PATH) == FAIL)
		return (FAIL);
	if (load_xpm_dir(s, p->death, P_DEATH_MAX, P_PATH) == FAIL)
		return (FAIL);
	s->load = 0;
	return (TRUE);
}
