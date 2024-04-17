/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mload.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:00:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 11:49:43 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "util.h"

static int	load_type(t_m	*m, char c, int w, int h)
{
	if (c == 'P')
	{
		m->start.x = w;
		m->start.y = h;
		return (P);
	}
	if (c == '0')
		return (S);
	if (c == '1')
		return (W);
	if (c == 'C')
	{
		m->collected++;
		return (C);
	}
	if (c == 'E')
		return (E);
	return (NON);
}

static t_b	load_map_w(t_m *m, char *line, int h)
{
	int		w;
	t_md	**md;

	md = m->md;
	if ((int)ft_strlen(line) != m->w - 1 || line[m->w - 2] != '\n')
		return (FAIL);
	w = 1;
	while (w < m->w - 1)
	{
		md[h][w].t = load_type(m, line[w - 1], w, h);
		if (md[h][w].t == NON)
			return (FAIL);
		md[h][w].wt = N;
		w++;
	}
	free(line);
	return (TRUE);
}

t_b	load_map_h(t_m *m, char *path)
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
		if (line < 0)
			return (FAIL);
		if (!line)
			break ;
		if (load_map_w(m, line, h) == FAIL)
			return (FAIL);
		h++;
	}
	close(fd);
	return (TRUE);
}

t_b	load_m_data(t_m *m, char *path)
{
	int	h;
	int	w;

	if (load_map_h(m, path) == FAIL)
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

t_b	load_m_image(t_s *s, t_m *m)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 5)
	{
		if (parse_path(&path, M_PATH, i, 0) == FAIL)
			return (FAIL);
		m->m_img[i] = load_xpm(s, path, 64, 64);
		if (!m->m_img[i])
			return (FAIL);
		free(path);
		i++;
	}
	while (i - 5 < 13)
	{
		if (parse_path(&path, W_PATH, i - 5, 0) == FAIL)
			return (FAIL);
		m->w_img[i - 5] = load_xpm(s, path, 64, 64);
		if (!m->w_img[i - 5])
			return (FAIL);
		free(path);
		i++;
	}
	return (TRUE);
}
