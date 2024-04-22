/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:25:57 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:48 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_b	check_dup_zombie(t_zi *zombies, t_zi *zombie, int cur)
{
	int	i;

	i = 0;
	while (i < cur)
	{
		if (zombies[i].loc.x == zombie->loc.x
			&& zombies[i].loc.y == zombie->loc.y)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	spawn_zombie(t_s *s, t_zi *zombies)
{
	int	i;

	i = 0;
	while (i < s->z_num)
	{
		zombies[i].loc.x = rand() % s->map.w;
		zombies[i].loc.y = rand() % s->map.h;
		if (s->map.start.x - 2 <= zombies[i].loc.x
			&& zombies[i].loc.x <= s->map.start.x + 2)
			if (s->map.start.y - 2 <= zombies[i].loc.y
				&& zombies[i].loc.y <= s->map.start.y + 2)
				continue ;
		if (s->map.md[zombies[i].loc.y][zombies[i].loc.x].t != S)
			continue ;
		if (!check_dup_zombie(s->zombies, &zombies[i], i))
			continue ;
		zombies[i].start.x = zombies[i].loc.x;
		zombies[i].start.y = zombies[i].loc.y;
		zombies[i].loc.x = zombies[i].start.x * 64;
		zombies[i].loc.y = zombies[i].start.y * 64;
		i++;
	}
}

static t_b	create_zombie(t_s *s)
{
	int	i;

	s->zombies = (t_zi *)ft_calloc(sizeof(t_zi), s->z_num);
	if (!s->zombies)
		return (FAIL);
	i = 0;
	while (i < s->z_num)
	{
		s->zombies[i].ctime = 0;
		s->zombies[i].time = 0;
		s->zombies[i].frame = 0;
		s->zombies[i].dir = rand() % DIRECTION;
		s->zombies[i].action = rand() % 2;
		s->zombies[i].target = NULL;
		i++;
	}
	spawn_zombie(s, s->zombies);
	return (TRUE);
}

t_b	load_zombie(t_s *s, t_zd *zd)
{
	zd->sp = 2;
	zd->mark = NULL;
	zd->idle = NULL;
	zd->run = NULL;
	zd->mark = load_xpms(s, ZOMBIE_MARK_PATH, ZOMBIE_MARK_MAX);
	if (!zd->mark)
		return (FAIL);
	zd->idle = load_xpmss(s, ZOMBIE_IDLE_PATH, DIRECTION, ZOMBIE_IDLE_MAX);
	if (!zd->idle)
		return (FAIL);
	zd->run = load_xpmss(s, ZOMBIE_RUN_PATH, DIRECTION, ZOMBIE_RUN_MAX);
	if (!zd->run)
		return (FAIL);
	if (create_zombie(s) == FAIL)
		return (FAIL);
	return (TRUE);
}
