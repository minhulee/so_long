/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:46:40 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:02 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	detect_front(t_md **target, t_v loc, int sp, t_md **md)
{
	int	x;
	int	y;

	y = loc.y + (46 + 16) + sp;
	x = loc.x + 16;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[y / SIZE][(x + 34) / SIZE];
	return (63 - ((y - sp) % SIZE));
}

int	detect_back(t_md **target, t_v loc, int sp, t_md **md)
{
	int	x;
	int	y;

	y = loc.y + 46 - sp;
	x = loc.x + 16;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[y / SIZE][(x + 34) / SIZE];
	return ((y + sp) % SIZE - 2);
}

int	detect_left(t_md **target, t_v loc, int sp, t_md **md)
{
	int	x;
	int	y;

	y = loc.y + 46;
	x = loc.x + 16 - sp;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[(y + 16) / SIZE][x / SIZE];
	return ((x + sp) % SIZE - 2);
}

int	detect_right(t_md **target, t_v loc, int sp, t_md **md)
{
	int	x;
	int	y;

	y = loc.y + 46;
	x = loc.x + (16 + 34) + sp;
	target[0] = &md[y / SIZE][x / SIZE];
	target[1] = &md[(y + 16) / SIZE][x / SIZE];
	return (63 - ((x - sp) % SIZE));
}
