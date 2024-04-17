/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 07:47:17 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/16 06:49:21 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "util.h"

static void	bfs(t_m *m, t_md **md, int h, int w)
{
	if (h == 0 || h == m->h - 1)
		return ;
	if (w == 0 || w == m->w - 1)
		return ;
	if (md[h][w].t == W)
		return ;
	if (md[h][w].visited == TRUE)
		return ;
	md[h][w].visited = TRUE;
	bfs(m, md, h + 1, w);
	bfs(m, md, h - 1, w);
	bfs(m, md, h, w - 1);
	bfs(m, md, h, w + 1);
}

t_b	check_bfs_res(t_m *m, t_md **md)
{
	int	h;
	int	w;

	bfs(m, md, m->start.x, m->start.y);
	h = 1;
	while (h < m->h - 1)
	{
		w = 1;
		while (w < m->w - 1)
		{
			if (md[h][w].t == C && md[h][w].visited == FALSE)
				return (FAIL);
			if (md[h][w].t == E && md[h][w].visited == FALSE)
				return (FAIL);
			md[h][w].visited = FALSE;
			w++;
		}
		h++;
	}
	return (TRUE);
}