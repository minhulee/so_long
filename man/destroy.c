/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:15:36 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 12:28:25 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_m *m)
{
	int	h;

	if (m->md == NULL)
		return ;
	h = 0;
	while (h < m->h)
	{
		free(m->md[h]);
		m->md[h] = NULL;
		h++;
	}
	free(m->md);
	m->md = NULL;
}

void	destroy_images(t_s *s)
{
	int	i;

	i = 0;
	while (i < s->loaded && s->images[i])
	{
		mlx_destroy_image(s->mlx, s->images[i]->img);
		free(s->images[i]);
		s->images[i] = NULL;
		i++;
	}
}

int	destroy_game(t_s *s)
{
	mlx_clear_window(s->mlx, s->win);
	mlx_destroy_window(s->mlx, s->win);
	destroy_images(s);
	destroy_map(&s->map);
	printf("Bye Bye!");
	exit(0);
	return (0);
}
