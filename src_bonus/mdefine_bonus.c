/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdefine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:40:53 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:05:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	define_wall_type_5(t_md **md, int h, int w)
{
	if (md[h][w + 1].t > W && md[h][w - 1].t <= W)
	{
		if (md[h - 1][w].t > W && md[h + 1][w].t > W)
			md[h][w].wt = T;
		else if ((md[h - 1][w].t <= W && md[h + 1][w].t <= W)
			&& (md[h - 1][w - 1].t > W && md[h + 1][w - 1].t <= W))
			md[h][w].wt = TR;
		else if (md[h - 1][w - 1].t > W || md[h + 1][w - 1].t > W)
			md[h][w].wt = BOTH_H;
		else if (md[h - 1][w].t <= W || md[h + 1][w].t <= W)
			md[h][w].wt = L;
	}
	else if (md[h][w - 1].t > W && md[h][w + 1].t <= W)
	{
		if (md[h - 1][w].t > W && md[h + 1][w].t > W)
			md[h][w].wt = T;
		else if ((md[h - 1][w].t <= W && md[h + 1][w].t <= W)
			&& (md[h - 1][w + 1].t > W && md [h + 1][w + 1].t <= W))
			md[h][w].wt = TL;
		else if (md[h - 1][w + 1].t > W || md[h + 1][w + 1].t > W)
			md[h][w].wt = BOTH_H;
		else if (md[h - 1][w].t <= W || md[h + 1][w].t <= W)
			md[h][w].wt = R;
	}
}

void	define_wall_type_4(t_md **md, int h, int w)
{
	if (md[h - 1][w].t > W && md[h + 1][w].t <= W)
	{
		if ((md[h][w - 1].t <= W && md[h][w + 1].t <= W)
			&& (md[h + 1][w - 1].t <= W && md[h + 1][w + 1].t <= W))
			md[h][w].wt = B;
		else if (md[h][w + 1].t <= W && md[h + 1][w + 1].t <= W)
			md[h][w].wt = TL;
		else if (md[h][w - 1].t <= W && md[h + 1][w - 1].t <= W)
			md[h][w].wt = TR;
		else
			md[h][w].wt = BOTH_H;
	}
	else if (md[h + 1][w].t > W && md[h - 1][w].t <= W)
		md[h][w].wt = T;
	else
		define_wall_type_5(md, h, w);
}

void	define_wall_type_3(t_md **md, int h, int w)
{
	if (md[h - 1][w + 1].t > W)
	{
		if (md[h + 1][w - 1].t > W)
			md[h][w].wt = TL;
		else
			md[h][w].wt = BL;
	}
	else if (md[h + 1][w - 1].t > W)
		md[h][w].wt = R;
	else if (md[h + 1][w + 1].t > W)
		md[h][w].wt = L;
	else
		md[h][w].wt = D;
}

void	define_wall_type_2(t_md **md, int h, int w)
{
	if ((md[h - 1][w - 1].t > W && md[h - 1][w + 1].t > W)
		&& (md[h + 1][w - 1].t > W && md[h + 1][w + 1].t > W))
			md[h][w].wt = BOTH_H;
	else if (md[h - 1][w - 1].t > W && md[h - 1][w + 1].t > W)
		md[h][w].wt = BOTH_B;
	else if (md[h + 1][w - 1].t > W && md[h + 1][w + 1].t > W)
		md[h][w].wt = BOTH_H;
	else if (md[h - 1][w - 1].t > W)
	{
		if (md[h + 1][w + 1].t > W)
			md[h][w].wt = TR;
		else
			md[h][w].wt = BR;
	}
	else
		define_wall_type_3(md, h, w);
}

void	define_wall_type_1(t_md **md, int h, int w)
{
	md[h][w].wt = UDEF;
	if (md[h - 1][w].t <= W && md[h + 1][w].t <= W
		&& md[h][w - 1].t <= W && md[h][w + 1].t <= W)
		define_wall_type_2(md, h, w);
	else if ((md[h - 1][w].t <= W && md[h + 1][w].t <= W)
		&& (md[h][w - 1].t > W && md[h][w + 1].t > W))
		md[h][w].wt = BOTH_H;
	else if ((md[h - 1][w].t > W && md[h + 1][w].t > W)
		&& (md[h][w - 1].t <= W && md[h][w + 1].t <= W))
		md[h][w].wt = T;
	else if (md[h - 1][w].t > W && md[h + 1][w].t <= W)
	{
		if ((md[h][w - 1].t <= W && md[h][w + 1].t <= W)
			&& (md[h + 1][w - 1].t <= W && md[h + 1][w + 1].t <= W))
			md[h][w].wt = B;
		else if (md[h][w + 1].t <= W && md[h + 1][w + 1].t <= W)
			md[h][w].wt = TL;
		else if (md[h][w - 1].t <= W && md[h + 1][w - 1].t <= W)
			md[h][w].wt = TR;
		else
			md[h][w].wt = BOTH_H;
	}
	else
		define_wall_type_4(md, h, w);
}
