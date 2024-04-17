/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrender.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:21:33 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 11:31:33 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "so_long.h"

static void	put_dtblr_tl_tr(t_s *s, int w, int h, t_wt type)
{
	int	x;
	int	y;

	x = 64 * w;
	y = 64 * h;
	if (type == D)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[D], x, y);
	else if (type == T)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[T], x, y);
	else if (type == L)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[L], x, y);
	else if (type == R)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[R], x, y);
	else if (type == B)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[B], x, y);
	else if (type == TL)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[TL], x, y);
	else if (type == TR)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[TR], x, y);
}

static void	put_b_lr_bt_hwb_ct(t_s *s, int w, int h, t_wt type)
{
	int	x;
	int	y;

	x = 64 * w;
	y = 64 * h;
	if (type == BL)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[BL], x, y);
	else if (type == BR)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[BR], x, y);
	else if (type == BOTH_H)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[BOTH_H], x, y);
	else if (type == BOTH_W)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[BOTH_W], x, y);
	else if (type == BOTH_B)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[BOTH_B], x, y);
	else if (type == CT)
		mlx_put_image_to_window(s->mlx, s->win, s->map.w_img[CT], x, y);
}

static void	put_s_c_e(t_s *s, int w, int h, t_t type)
{
	int	x;
	int	y;

	x = 64 * w;
	y = 64 * h;
	mlx_put_image_to_window(s->mlx, s->win, s->map.m_img[3], x, y);
	if (type == C && s->map.md[h][w].visited == FALSE)
	{
		if (s->player.target != &s->map.md[h][w])
			mlx_put_image_to_window(s->mlx, s->win, s->map.m_img[1], x, y);
		else
			mlx_put_image_to_window(s->mlx, s->win, s->map.m_img[2], x, y);
		mlx_put_image_to_window(s->mlx, s->win,
			s->map.collect->img, x + 8, y + 8);
	}
	else if (type == E)
	{
		mlx_put_image_to_window(s->mlx, s->win, s->map.m_img[4], x, y);
		if (s->map.collected == 0)
			mlx_put_image_to_window(s->mlx, s->win,
				s->map.arrow->img, x, y - 30);
	}
}

void	read_map(t_s *s, t_m *m, t_md **md)
{
	int	w;
	int	h;

	h = 0;
	while (h < m->h)
	{
		w = 0;
		while (w < m->w)
		{
			if (md[h][w].t == W || md[h][w].t == N)
			{
				put_dtblr_tl_tr(s, w, h, md[h][w].wt);
				put_b_lr_bt_hwb_ct(s, w, h, md[h][w].wt);
			}
			else
				put_s_c_e(s, w, h, md[h][w].t);
			w++;
		}
		h++;
	}
}
