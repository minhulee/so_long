/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:15:36 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:00 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_map(t_m *m)
{
	int	h;

	free_xpms(m->map);
	free_xpms(m->wall);
	free_xpms(m->collect);
	free_xpms(m->arrow);
	if (!m->md)
		return ;
	h = 0;
	while (h < m->h)
	{
		free(m->md[h]);
		m->md[h] = NULL;
		h++;
	}
	free(m->md);
	m->md = NULL;
}

void	destroy_player(t_p *p)
{
	free_xpmss(p->idle, DIRECTION);
	free_xpmss(p->run, DIRECTION);
	free_xpmss(p->death, DIRECTION);
}

static void	destroy_zombie(t_zd *zd, t_zi *zombies)
{
	free_xpmss(zd->idle, DIRECTION);
	free_xpmss(zd->run, DIRECTION);
	free_xpms(zd->mark);
	if (zombies)
		free(zombies);
	zombies = NULL;
}

void	destroy_images(t_s *s)
{
	int	i;

	if (!s->images[0])
		return ;
	i = 0;
	while (i < s->loaded)
	{
		mlx_destroy_image(s->mlx, s->images[i]);
		s->images[i] = NULL;
		i++;
	}
}

int	destroy_game(t_s *s)
{
	s->clear = TRUE;
	s->print = TRUE;
	if (s->win)
	{
		mlx_clear_window(s->mlx, s->win);
		mlx_destroy_window(s->mlx, s->win);
	}
	destroy_images(s);
	destroy_map(&s->map);
	destroy_player(&s->player);
	destroy_zombie(&s->zd, s->zombies);
	ft_printf("destroy game...\n");
	return (0);
}
