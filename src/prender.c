/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prender.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:37:26 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 10:24:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_player_action(t_p *p, t_a action, t_dir dir, int frame)
{
	if (action == IDLE)
		return (p->idle[dir][frame]);
	else if (action == RUN)
		return (p->run[dir][frame]);
	else if (action == DEATH)
		return (p->death[dir][frame]);
	return (NULL);
}

void	prender(t_s *s, t_p *p)
{
	mlx_put_image_to_window(s->mlx, s->win,
		load_player_action(p, p->action, p->dir, p->frame), p->loc.x, p->loc.y);
	if (p->target && p->target->t == E && s->map.collected <= 0)
		mlx_put_image_to_window(s->mlx, s->win,
			p->mark[1], p->loc.x + 16, p->loc.y + 46);
	else
		mlx_put_image_to_window(s->mlx, s->win,
			p->mark[0], p->loc.x + 16, p->loc.y + 46);
}
