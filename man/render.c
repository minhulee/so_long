/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:58:14 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:56:18 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "so_long.h"

void	put_moved(t_s *s)
{
	char	*move;
	char	*itoa;

	itoa = ft_itoa(s->moved);
	if (!itoa)
		exit_err(s, "ERROR\n :: moved print failed ::");
	move = ft_strjoin("Moved : ", itoa);
	if (!move)
	{
		free(itoa);
		exit_err(s, "ERROR\n :: moved print failed");
	}
	mlx_string_put(s->mlx, s->win, 20, 40, 0xFFFFFF, move);
	free(move);
}

void	render_window(t_s *s, t_p *p)
{	
	if (s->time == 300)
	{
		mlx_clear_window(s->mlx, s->win);
		read_map(s, &s->map, s->map.md);
		if (p->cur == RUN)
			move(s, p);
		mlx_put_image_to_window(s->mlx, s->win,
			load_action(p), p->loc.x, p->loc.y);
		if (p->target && p->target->t == E && s->map.collected <= 0)
			mlx_put_image_to_window(s->mlx, s->win,
				s->mark[1], p->loc.x + 16, p->loc.y + 46);
		else
			mlx_put_image_to_window(s->mlx, s->win,
				s->mark[0], p->loc.x + 16, p->loc.y + 46);
		put_moved(s);
		s->time = 0;
	}
}

void	update_time(t_s *s)
{
	s->time++;
	s->player.time++;
	s->map.time++;
}

void	update_collect(t_m *m)
{
	if (m->time == 3500)
	{
		m->collect = m->collect->next;
		m->arrow = m->arrow->next;
		m->time = 0;
	}
}

int	render(t_s *s)
{
	update_time(s);
	if (!s->clear.c)
	{
		update_input(s);
		update_player(s, &s->player);
		update_collect(&s->map);
		render_window(s, &s->player);
	}
	else if (!s->print)
		render_swirl(s);
	return (TRUE);
}
