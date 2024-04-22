/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:27:03 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:55:44 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collision(t_s *s, t_v ploc, t_zi *zombies)
{
	int		i;
	t_zi	zi;

	i = 0;
	while (i < s->z_num)
	{
		zi = zombies[i];
		if ((ploc.x <= zi.loc.x && zi.loc.x <= ploc.x + 34)
			|| (ploc.x <= zi.loc.x + 34 && zi.loc.x + 34 <= ploc.x + 34))
		{
			if ((ploc.y <= zi.loc.y && zi.loc.y <= ploc.y + 16)
				|| (ploc.y <= zi.loc.y + 16 && zi.loc.y + 16 <= ploc.y + 16))
			{
				s->player.action = DEATH;
				s->player.time = 0;
				s->player.frame = 0;
				break ;
			}
		}
		i++;
	}
}

void	player_to_detect(t_s *s, int dir, t_p *p, t_md **md)
{	
	t_md	*target[2];
	int		sp;

	if (dir == FRONT)
		sp = detect_front(target, p->loc, p->sp, md);
	else if (dir == BACK)
		sp = detect_back(target, p->loc, p->sp, md);
	else if (dir == LEFT)
		sp = detect_left(target, p->loc, p->sp, md);
	else if (dir == RIGHT)
		sp = detect_right(target, p->loc, p->sp, md);
	if (target[0] == target[1] && (target[0]->t == C || target[0]->t == E))
		p->target = target[0];
	else
		p->target = NULL;
	if ((target[0]->t == C && !target[0]->visited)
		|| (target[1]->t == C && !target[1]->visited)
		|| (target[0]->t == W || target[1]->t == W))
		pmove(s, p, sp);
	else
		pmove(s, p, p->sp);
}

void	zombie_to_detect(t_s *s, int dir, t_zi *zi, t_md **md)
{	
	t_md	*target[2];
	int		sp;

	if (dir == FRONT)
		sp = detect_front(target, zi->loc, s->zd.sp, md);
	else if (dir == BACK)
		sp = detect_back(target, zi->loc, s->zd.sp, md);
	else if (dir == LEFT)
		sp = detect_left(target, zi->loc, s->zd.sp, md);
	else if (dir == RIGHT)
		sp = detect_right(target, zi->loc, s->zd.sp, md);
	if ((target[0]->t == C && !target[0]->visited)
		|| (target[1]->t == C && !target[1]->visited)
		|| (target[0]->t == W || target[1]->t == W))
		zmove(zi, 0);
	else
		zmove(zi, s->zd.sp);
}
