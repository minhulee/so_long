/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:22:55 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/23 10:36:45 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

t_b	valid_format(char *path)
{
	char	**split;
	char	*start;
	int		i;
	int		len;

	split = ft_split(path, '/');
	i = 0;
	while (split[i] != NULL)
		i++;
	len = ft_strlen(split[i - 1]);
	start = ft_strnstr(split[i - 1], ".bar", len);
	if ((start + 3) != &split[i - 1][len - 1])
	{
		free_split(split);
		ft_printf("Error\nso_long :: invalid file format ::");
		exit(1);
	}
	free_split(split);
	return (TRUE);
}

void	exit_err(char *errstr)
{
	if (!errstr)
		errstr = "ERROR\n :: invalid err str ::\n";
	ft_printf("%s\n", errstr);
	exit(1);
}

static t_b	load_game(t_s *s, char *path)
{
	char	*err;

	err = NULL;
	if (load_system(s) == FAIL)
		exit_err("ERROR\n :: system create failed ::");
	err = load_map(s, &s->map, path);
	if (err)
	{
		destroy_game(s);
		exit_err(err);
	}
	if (s->z_num > 30)
		s->z_num = (s->map.w * s->map.h) / s->z_num + 1;
	else
		s->z_num = 0;
	if (load_player(s, &s->player) == FAIL)
	{
		destroy_game(s);
		exit_err("ERROR\n :: player load failed ::");
	}
	ft_printf("load_player\n");
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_s	s;

	if (ac != 2)
		exit_err("Error\n :: invalid av input ::");
	valid_format(av[1]);
	load_game(&s, av[1]);
	s.win = mlx_new_window(s.mlx, s.win_size.x, s.win_size.y, TITLE);
	if (!s.win)
	{
		destroy_game(&s);
		exit_err("ERROR\n :: window create failed ::");
	}
	if (load_zombie(&s, &s.zd) == FAIL)
	{
		destroy_game(&s);
		exit_err("ERROR\n :: zombie load failed ::");
	}
	ft_printf("start.\n");
	mlx_hook(s.win, 2, 0, key_press, &s);
	mlx_hook(s.win, 3, 0, key_release, &s);
	mlx_hook(s.win, 17, 0, destroy_game, &s);
	mlx_loop_hook(s.mlx, render, &s);
	mlx_loop(s.mlx);
	return (TRUE);
}
