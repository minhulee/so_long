/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mload_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:00:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	load_type(t_s *s, char c, int w, int h)
{
	if (c == 'P')
	{
		s->map.start.x = w;
		s->map.start.y = h;
		return (P);
	}
	if (c == '0')
	{
		s->z_num++;
		return (S);
	}
	if (c == '1')
		return (W);
	if (c == 'C')
	{
		s->map.collected++;
		return (C);
	}
	if (c == 'E')
		return (E);
	return (NON);
}

static t_b	create_m_data(t_m	*m)
{
	int	h;
	int	w;

	if (m->h < 3)
		return (FAIL);
	m->md = (t_md **)ft_calloc(sizeof(t_md *), m->h);
	if (!m->md)
		return (FAIL);
	h = 0;
	while (h < m->h)
	{
		m->md[h] = (t_md *)ft_calloc(sizeof(t_md), m->w);
		if (!m->md[h])
			return (FAIL);
		w = 0;
		while (w < m->w)
		{
			m->md[h][w].t = N;
			m->md[h][w].wt = D;
			m->md[h][w].visited = FALSE;
			w++;
		}
		h++;
	}
	return (TRUE);
}

static t_b	load_map_w(t_s *s, t_m *m, char *line, int h)
{
	int		w;
	t_md	**md;

	md = m->md;
	if ((int)ft_strlen(line) != m->w - 1 || line[m->w - 2] != '\n')
		return (FAIL);
	w = 1;
	while (w < m->w - 1)
	{
		md[h][w].t = load_type(s, line[w - 1], w, h);
		if (md[h][w].t == NON)
			return (FAIL);
		md[h][w].wt = N;
		w++;
	}
	free(line);
	return (TRUE);
}

t_b	load_map_h(t_s *s, t_m *m, char *path)
{
	int		fd;
	char	*line;
	int		h;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (FAIL);
	h = 1;
	while (h < m->h - 1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (load_map_w(s, m, line, h) == FAIL)
			return (FAIL);
		h++;
	}
	close(fd);
	return (TRUE);
}

t_b	load_m_data(t_s *s, t_m *m, char *path)
{
	int	h;
	int	w;

	if (create_m_data(m) == FAIL)
		return (FAIL);
	if (load_map_h(s, m, path) == FAIL)
		return (FAIL);
	h = 1;
	while (h < m->h - 1)
	{
		w = 1;
		while (w < m->w - 1)
		{
			if (m->md[h][w].t == W)
			{
				define_wall_type_1(m->md, h, w);
				if (m->md[h][w].wt == UDEF)
					m->md[h][w].wt = CT;
			}
			w++;
		}
		h++;
	}
	return (TRUE);
}
