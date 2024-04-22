/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physic_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:12:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:12:53 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect(t_s *s)
{
	if (s->player.target->t == C && s->player.target->visited == FALSE)
	{
		s->player.target->visited = TRUE;
		s->map.collected--;
	}
	if (s->player.target->t == E && s->map.collected <= 0)
	{
		init_swirl(&s->swirl);
		s->time = 0;
		s->clear = TRUE;
	}
}

void	zmove(t_zi *zi, int sp)
{
	if (zi->dir == FRONT)
		zi->loc.y += sp;
	else if (zi->dir == LEFT)
		zi->loc.x -= sp;
	else if (zi->dir == RIGHT)
		zi->loc.x += sp;
	else
		zi->loc.y -= sp;
}

void	pmove(t_s *s, t_p *p, int sp)
{
	if (sp == 0)
		return ;
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
