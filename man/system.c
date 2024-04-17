/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:28:04 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:53:57 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "util.h"

void	reset_map_data(t_m *m, t_md **md)
{
	int	h;
	int	w;

	h = 1;
	while (h < m->h - 1)
	{
		w = 1;
		while (w < m->w - 1)
		{
			md[h][w].visited = FALSE;
			w++;
		}
		h++;
	}
	m->collected = m->max_collected;
}

void	game_reset(t_s *s)
{
	s->player.deathd = FALSE;
	s->player.cur = IDLE;
	s->player.death[s->player.dir] = s->player.death[s->player.dir]->next;
	s->player.loc.x = s->map.start.x * 64;
	s->player.loc.y = s->map.start.y * 64 - 20;
	s->player.target = NULL;
	s->moved = 0;
	reset_map_data(&s->map, s->map.md);
	s->time = 0;
	s->clear.loc.x = 0;
	s->clear.loc.y = 0;
	s->clear.r = 0;
	s->clear.t = FALSE;
	s->clear.c = !s->clear.c;
	s->print = FALSE;
	ft_printf("restart...\nMOVE : %d\n", s->moved);
}

static void	init_system(t_s *s)
{
	int	i;

	s->load = 0;
	s->loaded = 0;
	s->moved = 0;
	s->size = 64;
	s->time = 0;
	s->mark[0] = NULL;
	s->mark[1] = NULL;
	s->z_num = 0;
	s->clear.c = FALSE;
	s->clear.loc.x = 0;
	s->clear.loc.y = 0;
	s->clear.r = 0;
	s->clear.t = FALSE;
	i = 0;
	while (i < IMAGE)
	{
		s->images[i] = NULL;
		i++;
	}
	return ;
}

t_b	load_system(t_s *s)
{
	init_system(s);
	s->mlx = mlx_init();
	if (!s->mlx)
		return (FAIL);
	s->mark[0] = load_xpm(s, "./textures/0.xpm", 64, 64);
	if (!s->mark[0])
		return (FAIL);
	s->mark[1] = load_xpm(s, "./textures/1.xpm", 64, 64);
	if (!s->mark[1])
		return (FAIL);
	return (TRUE);
}
