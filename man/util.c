/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:17:06 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:04:11 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "so_long.h"

t_b	parse_path(char **target, char *path, int load, int pre)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(path, ft_itoa(load + pre));
	if (!tmp)
		return (FAIL);
	res = ft_strjoin(tmp, ".xpm");
	free(tmp);
	if (!res)
		return (FAIL);
	*target = res;
	return (TRUE);
}

t_b	new_image(t_s *s, t_img **target, char *p_path)
{
	t_img	*new;

	new = malloc(sizeof(t_img));
	if (!new)
		return (FAIL);
	new->img = mlx_xpm_file_to_image(s->mlx,
			p_path, &s->size, &s->size);
	free(p_path);
	if (!new->img)
	{
		free(new);
		return (FAIL);
	}
	new->next = NULL;
	if (!*target)
		*target = new;
	else
	{
		(*target)->next = new;
		*target = (*target)->next;
	}
	return (TRUE);
}

void	*load_xpm(t_s *s, char *path, int x, int y)
{
	t_img	*temp;

	temp = (t_img *)malloc(sizeof(t_img));
	if (!temp)
		return (NULL);
	temp->img = mlx_xpm_file_to_image(s->mlx, path, &x, &y);
	if (!temp->img)
	{
		free(temp);
		return (NULL);
	}
	temp->next = NULL;
	s->images[s->loaded] = temp;
	s->loaded++;
	return (temp->img);
}

t_b	load_xpm_t_img(t_s *s, t_img **target, int max, char *path)
{
	int		load;
	char	*p_path;
	t_img	*start;

	load = 0;
	while (load < max)
	{
		if (parse_path(&p_path, path, load, s->load) == FAIL)
			return (FAIL);
		if (new_image(s, target, p_path) == FAIL)
			return (FAIL);
		(s->images)[s->loaded] = *target;
		s->loaded++;
		if (load % max == 0)
			start = (*target);
		if (load == max - 1)
		{
			(*target)->next = start;
			(*target) = start;
		}
		load++;
	}
	return (TRUE);
}

t_b	load_xpm_dir(t_s *s, t_img **target, int max, char *path)
{
	int		load;
	char	*p_path;
	t_img	*start;

	load = 0;
	while (load < 4 * max)
	{
		if (parse_path(&p_path, path, load, s->load) == FAIL)
			return (FAIL);
		if (new_image(s, &target[load / max], p_path) == FAIL)
			return (FAIL);
		(s->images)[s->loaded] = target[load / max];
		s->loaded++;
		if (load % max == 0)
			start = target[load / max];
		if (load == (load / max + 1) * max - 1)
		{
			target[load / max]->next = start;
			target[load / max] = start;
		}
		load++;
	}
	s->load += load;
	return (TRUE);
}
