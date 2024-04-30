/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:26:32 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/23 11:00:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*map_size(t_m *m, char *path)
{
	int		fd;
	char	c;
	int		res;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ("ERROR\n :: file does not exist ::");
	while (TRUE)
	{
		res = read(fd, &c, 1);
		if (res < 0)
			return ("ERROR\n :: map read failed ::");
		if (!res)
			break ;
		if (m->h == 2)
			m->w++;
		if (c == '\n')
			m->h++;
	}
	close(fd);
	if (c != '\n')
		return ("ERROR\n :: map shape is not rectangular ::");
	return (NULL);
}

static void	init_map(t_m *m)
{
	m->h = 2;
	m->w = 1;
	m->time = 0;
	m->frame = 0;
	m->collected = 0;
	m->md = NULL;
	m->map = NULL;
	m->wall = NULL;
	m->collect = NULL;
	m->arrow = NULL;
}

static char	*map_size_valid(t_s *s, t_m *m, char *path)
{
	char	*err;

	err = NULL;
	err = map_size(m, path);
	if (err)
		return (err);
	if (valid_map(m, path) == FAIL)
		return ("ERROR\n :: invalid map data ::");
	if (load_m_data(s, m, path) == FAIL)
		return ("ERROR\n :: map load failed ::");
	return (NULL);
}

char	*load_map(t_s *s, t_m *m, char *path)
{
	char	*err;

	init_map(m);
	err = map_size_valid(s, m, path);
	if (err)
		return (err);
	m->map = load_xpms(s, MAP_PATH, MAP_MAX);
	if (!m->map)
		return ("ERROR\n :: map image load failed ::");
	m->wall = load_xpms(s, MAP_WALL_PATH, MAP_WALL_MAX);
	if (!m->wall)
		return ("ERROR\n :: map image load failed ::");
	m->collect = load_xpms(s, MAP_COLLECT_PATH, MAP_COLLECT_MAX);
	if (!m->collect)
		return ("ERROR\n :: map image load failed ::");
	m->arrow = load_xpms(s, MAP_ARROW_PATH, MAP_ARROW_MAX);
	if (!m->arrow)
		return ("ERROR\n :: map image load failed ::");
	if (check_bfs_res(m, m->md) == FAIL)
		return ("ERROR\n :: invalid route in map ::");
	m->max_collected = m->collected;
	s->win_size.x = m->w * 64;
	s->win_size.y = m->h * 64;
	return (NULL);
}
