/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:12:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 14:04:23 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "util.h"



void	collect(t_s *s)
{
	if (s->player.target->t == C && s->player.target->visited == FALSE)
	{
		s->player.target->visited = TRUE;
		s->map.collected--;
	}
	if (s->player.target->t == E && s->map.collected <= 0)
	{
		s->time = 0;
		s->clear.c = TRUE;
	}
}

void	move(t_s *s, t_p *p)
{
	int	sp;

	sp = dir_to_detect(p->dir, p, s->map.md);
	if (p->dir == FRONT)
		p->loc.y += sp;
	else if (p->dir == LEFT)
		p->loc.x -= sp;
	else if (p->dir == RIGHT)
		p->loc.x += sp;
	else
		p->loc.y -= sp;
	s->moved++;
	ft_printf("MOVE : %d\n", s->moved);
}
