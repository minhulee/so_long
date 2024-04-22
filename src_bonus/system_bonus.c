/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:28:04 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:06:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_swirl(t_ss *swirl)
{
	swirl->loc.x = 0;
	swirl->loc.y = 0;
	swirl->r = 0;
	swirl->t = FALSE;
}

static void	init_system(t_s *s)
{
	int	i;

	s->loaded = 0;
	s->moved = 0;
	s->size = 64;
	s->time = 0;
	s->z_num = 0;
	s->clear = FALSE;
	s->print = FALSE;
	s->zombies = NULL;
	s->win = NULL;
	init_swirl(&s->swirl);
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
	return (TRUE);
}
