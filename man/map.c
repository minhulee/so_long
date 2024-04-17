/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:26:32 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:04:16 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "util.h"
#include <sys/fcntl.h>

static t_b	map_size(t_s *s, t_m *m, char *path)
{
	int		fd;
	char	c;
	int		res;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_err(s, "ERROR\n :: file does not exist ::");
	while (TRUE)
	{
		res = read(fd, &c, 1);
		if (res < 0)
			exit_err(s, "ERROR\n :: map read failed ::");
		if (!res)
			break ;
		if (m->h == 2)
			m->w++;
		if (c == '\n')
			m->h++;
	}
	close(fd);
	if (c != '\n')
		return (FAIL);
	return (TRUE);
}

static void	set_md(t_m *m, t_md **md)
{
	int	h;
	int	w;

	h = 0;
	while (h < m->h)
	{
		w = 0;
		while (w < m->w)
		{
			md[h][w].t = N;
			md[h][w].wt = D;
			md[h][w].visited = FALSE;
			w++;
		}
		h++;
	}
}

static t_b	create_m_data(t_m	*m)
{
	int	h;

	if (m->h < 3)
		return (FAIL);
	m->md = (t_md **)malloc(sizeof(t_md *) * m->h);
	if (!m->md)
		return (FAIL);
	h = 0;
	while (h < m->h)
	{
		m->md[h] = (t_md *)malloc(sizeof(t_md) * m->w);
		if (!m->md[h])
			return (FAIL);
		h++;
	}
	set_md(m, m->md);
	return (TRUE);
}

char	*load_map(t_s *s, t_m *m, char *path)
{
	m->h = 2;
	m->w = 1;
	m->time = 0;
	m->collected = 0;
	m->collect = NULL;
	m->arrow = NULL;
	if (map_size(s, m, path) == FAIL)
		return ("ERROR\n :: invalid map size ::");
	if (valid_map(m, path) == FAIL)
		return ("ERROR\n :: invalid map data ::");
	if (create_m_data(m) == FAIL)
		return ("ERROR\n :: map data creat failed ::");
	if (load_m_data(m, path) == FAIL)
		return ("ERROR\n :: map load failed ::");
	if (load_m_image(s, m) == FAIL
		|| load_xpm_t_img(s, &m->collect, 4, "./textures/map/collect/") == FAIL
		|| load_xpm_t_img(s, &m->arrow, 4, "./textures/map/arrow/") == FAIL)
		return ("ERROR\n :: map image load failed ::");
	if (check_bfs_res(m, m->md) == FAIL)
		return ("ERROR\n :: invalid route in map ::");
	m->max_collected = m->collected;
	s->win_size.x = m->w * 64;
	s->win_size.y = m->h * 64;
	return (NULL);
}
