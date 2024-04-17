/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:46:40 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:44:06 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "so_long.h"

static int	detect_front(t_md **target, t_p *p, t_md **md)
{
	int	x;
	int	y;

	y = p->loc.y + (46 + 16) + p->sp;
	x = p->loc.x + 16;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[y / SIZE][(x + 34) / SIZE];
	return (63 - ((y - p->sp) % SIZE));
}

static int	detect_back(t_md **target, t_p *p, t_md **md)
{
	int	x;
	int	y;

	y = p->loc.y + 46 - p->sp;
	x = p->loc.x + 16;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[y / SIZE][(x + 34) / SIZE];
	return ((y + p->sp) % SIZE - 2);
}

static int	detect_left(t_md **target, t_p *p, t_md **md)
{
	int	x;
	int	y;

	y = p->loc.y + 46;
	x = p->loc.x + 16 - p->sp;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[(y + 16) / SIZE][x / SIZE];
	return ((x + p->sp) % SIZE - 2);
}

static int	detect_right(t_md **target, t_p *p, t_md **md)
{
	int	x;
	int	y;

	y = p->loc.y + 46;
	x = p->loc.x + (16 + 34) + p->sp;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[(y + 16) / SIZE][x / SIZE];
	return (63 - ((x - p->sp) % SIZE));
}

int	dir_to_detect(int dir, t_p *p, t_md **md)
{	
	t_md	*target[2];
	int		sp;

	if (dir == FRONT)
		sp = detect_front(target, p, md);
	else if (dir == BACK)
		sp = detect_back(target, p, md);
	else if (dir == LEFT)
		sp = detect_left(target, p, md);
	else if (dir == RIGHT)
		sp = detect_right(target, p, md);
	if (target[0] == target[1] && (target[0]->t == C || target[0]->t == E))
		p->target = target[0];
	else
		p->target = NULL;
	if ((target[0]->t == C && !target[0]->visited)
		|| (target[1]->t == C && !target[1]->visited)
		|| (target[0]->t == W || target[1]->t == W))
		return (sp);
	return (p->sp);
}
