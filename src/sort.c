/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:10:27 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 16:37:18 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compare_zombie_to_y(const void *comp1, const void *comp2)
{
	t_zi	*target1;
	t_zi	*target2;

	target1 = (t_zi *)comp1;
	target2 = (t_zi *)comp2;
	return (target1->loc.y - target2->loc.y);
}

void	sort_zombie_to_y(t_s *s, t_zi *zombies)
{
	qsort(zombies, s->z_num, sizeof(t_zi), compare_zombie_to_y);
}
