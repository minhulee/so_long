/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:26:32 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_player(t_s *s, t_p *p)
{
	p->action = IDLE;
	p->dir = FRONT;
	p->time = 0;
	p->sp = 4;
	p->target = NULL;
	p->loc.x = s->map.start.x * 64;
	p->loc.y = s->map.start.y * 64 - 20;
	p->mark = NULL;
	p->idle = NULL;
	p->run = NULL;
	p->death = NULL;
	p->frame = 0;
	p->input[FRONT] = FALSE;
	p->input[LEFT] = FALSE;
	p->input[RIGHT] = FALSE;
	p->input[BACK] = FALSE;
}

t_b	load_player(t_s *s, t_p *p)
{
	init_player(s, p);
	p->mark = load_xpms(s, PLAYER_MARK_PATH, PLAYER_MARK_MAX);
	if (!p->mark)
		return (FAIL);
	p->idle = load_xpmss(s, PLAYER_IDLE_PATH, DIRECTION, PLAYER_IDLE_MAX);
	if (!p->idle)
		return (FAIL);
	p->run = load_xpmss(s, PLAYER_RUN_PATH, DIRECTION, PLAYER_RUN_MAX);
	if (!p->run)
		return (FAIL);
	p->death = load_xpmss(s, PLAYER_DEATH_PATH, DIRECTION, PLAYER_DEATH_MAX);
	if (!p->death)
		return (FAIL);
	return (TRUE);
}
