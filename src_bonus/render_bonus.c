/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:58:14 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:23 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_moved(t_s *s)
{
	char	*move;
	char	*itoa;

	itoa = ft_itoa(s->moved);
	if (!itoa)
		exit_err("ERROR\n :: moved print failed ::");
	move = ft_strjoin("Moved : ", itoa);
	free(itoa);
	if (!move)
		exit_err("ERROR\n :: moved print failed");
	mlx_string_put(s->mlx, s->win, 20, 40, 0xFFFFFF, move);
	free(move);
}

static void	render_to_y(t_s *s, t_p *p, t_zi *zombies)
{
	int	i;

	sort_zombie_to_y(s, zombies);
	i = 0;
	while (i < s->z_num)
	{
		if (zombies[i].loc.y >= p->loc.y)
			break ;
		zrender(s, &zombies[i]);
		i++;
	}
	prender(s, p);
	while (i < s->z_num)
	{
		zrender(s, &zombies[i]);
		i++;
	}
}

static void	render_to_move(t_s *s, t_p *p, t_m *m, t_zi *zombies)
{
	int	i;

	if (p->action == RUN)
		player_to_detect(s, p->dir, p, s->map.md);
	i = 0;
	while (i < s->z_num)
	{
		if (zombies[i].action == RUN)
			zombie_to_detect(s, zombies[i].dir, &zombies[i], m->md);
		i++;
	}
}

static void	normal(t_s *s, t_p *p, t_m *m, t_zi *zombies)
{	
	if (s->time == 300)
	{
		mlx_clear_window(s->mlx, s->win);
		mrender(s, m, m->md);
		if (p->action != DEATH)
			collision(s, p->loc, zombies);
		render_to_y(s, p, zombies);
		render_to_move(s, p, m, zombies);
		put_moved(s);
		s->time = 0;
	}
}

int	render(t_s *s)
{
	update_time(s);
	if (!s->clear)
	{
		input(s);
		update_frame(s, &s->player, &s->map);
		normal(s, &s->player, &s->map, s->zombies);
	}
	else if (!s->print)
		srender(s);
	return (TRUE);
}
