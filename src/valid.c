/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:43:01 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 15:25:24 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*parse_path(char *path, int num, t_b deps)
{
	char	*numb;
	char	*tmp;
	char	*res;

	numb = ft_itoa(num);
	if (!numb)
		return (numb);
	tmp = ft_strjoin(path, numb);
	free(numb);
	if (!tmp)
		return (tmp);
	if (deps)
		res = ft_strjoin(tmp, "/");
	else
		res = ft_strjoin(tmp, ".xpm");
	free(tmp);
	return (res);
}

t_b	valid_flag(t_b flag[3])
{
	if (flag[0] != 1)
		return (FAIL);
	if (flag[1] < 1)
		return (FAIL);
	if (flag[2] != 1)
		return (FAIL);
	return (TRUE);
}

t_b	valid_t_b_line(t_m *m, char *line)
{
	int	w;

	w = 0;
	while (w < m->w - 2)
	{
		if (line[w] != '1')
		{
			free(line);
			return (FAIL);
		}
		w++;
	}
	return (TRUE);
}

t_b	valid_line(t_m *m, char *line, t_b (*flag)[3])
{
	int	w;

	if (line[0] != '1' || line[m->w - 2] != '\n')
	{
		free(line);
		return (FAIL);
	}
	w = 1;
	while (w < m->w - 2)
	{
		if (line[w] == 'P')
			(*flag)[0]++;
		else if (line[w] == 'C')
			(*flag)[1]++;
		else if (line[w] == 'E')
			(*flag)[2]++;
		w++;
	}
	return (TRUE);
}

t_b	valid_map(t_m *m, char *path)
{
	int		fd;
	int		h;
	int		flag[3];
	char	*line;

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (FAIL);
	h = 1;
	while (h < m->h - 1)
	{
		line = get_next_line(fd);
		if ((h == 1 || h == m->h - 2) && valid_t_b_line(m, line) == FAIL)
			return (FAIL);
		if (valid_line(m, line, &flag) == FAIL)
			return (FAIL);
		free(line);
		h++;
	}
	return (valid_flag(flag));
}
