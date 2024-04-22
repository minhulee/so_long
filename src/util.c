/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:17:06 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 15:36:14 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_xpms(void **xpms)
{
	if (!xpms)
		return (xpms);
	free(xpms);
	xpms = NULL;
	return (xpms);
}

void	*free_xpmss(void ***xpmss, int deps)
{
	int	i;

	if (!xpmss)
		return (xpmss);
	i = 0;
	while (i < deps && xpmss[i])
	{
		free(xpmss[i]);
		xpmss[i] = NULL;
		i++;
	}
	free(xpmss);
	xpmss = NULL;
	return (xpmss);
}

void	*load_xpm(t_s *s, char *path, int size)
{
	void	*xpm;

	xpm = mlx_xpm_file_to_image(s->mlx, path, &size, &size);
	if (!xpm)
		return (NULL);
	s->images[s->loaded] = xpm;
	s->loaded++;
	return (xpm);
}

void	**load_xpms(t_s *s, char *path, int max)
{
	void	**xpms;
	char	*p_path;
	int		i;

	xpms = (void **)ft_calloc(sizeof(void *), max);
	if (!xpms)
		return (xpms);
	i = 0;
	while (i < (int)max)
	{
		p_path = parse_path(path, i, FALSE);
		if (!p_path)
			return (free_xpms(xpms));
		xpms[i] = load_xpm(s, p_path, SIZE);
		free(p_path);
		if (!(xpms[i]))
			return (free_xpms(xpms));
		i++;
	}
	return (xpms);
}

void	***load_xpmss(t_s *s, char *path, int deps, int max)
{
	void	***xpmss;
	char	*p_path;
	int		i;

	xpmss = (void ***)ft_calloc(sizeof(void **), deps);
	if (!xpmss)
		return (xpmss);
	i = 0;
	while (i < (int)deps)
	{
		p_path = parse_path(path, i, TRUE);
		if (!p_path)
			return (free_xpmss(xpmss, deps));
		xpmss[i] = load_xpms(s, p_path, max);
		free(p_path);
		if (!(xpmss[i]))
			return (free_xpmss(xpmss, deps));
		i++;
	}
	return (xpmss);
}
