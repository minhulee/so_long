/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zrender_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:58:35 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:54 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*load_zombie_action(t_zd *zd, t_a action, t_dir dir, int frame)
{
	if (action == IDLE)
		return (zd->idle[dir][frame]);
	else if (action == RUN)
		return (zd->run[dir][frame]);
	else
		return (NULL);
}

void	zrender(t_s *s, t_zi *z)
{
	mlx_put_image_to_window(s->mlx, s->win,
		load_zombie_action(&s->zd, z->action, z->dir, z->frame),
		z->loc.x, z->loc.y);
	mlx_put_image_to_window(s->mlx, s->win,
		s->zd.mark[0], z->loc.x + 16, z->loc.y + 46);
}
