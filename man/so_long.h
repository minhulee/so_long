/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:49:39 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 13:53:25 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../man/map.h"
# include "../man/player.h"
#include "util.h"

# define TITLE "Zombie Run !!"

# define IMAGE 68
# define SIZE 64

# define DUP 999
# define NON 998

# define FULL_X 1920
# define FULL_Y 1080

typedef struct s_end
{
	t_b	c;
	t_v	loc;
	t_b	t;
	int	r;
}	t_e;

typedef struct s_system
{
	void	*mlx;
	void	*win;
	t_v		win_size;
	int		size;
	int		time;
	int		moved;
	int		load;
	int		loaded;
	int		z_num;
	void	*mark[2];
	t_m		map;
	t_p		player;
	t_img	*images[IMAGE];
	t_e		clear;
	t_b		print;
}	t_s;

/* System func */
t_b		load_system(t_s *s);
void	game_reset(t_s *sys);
/* + Error func */
void	exit_err(t_s *s, char *errstr);

/* Destroy func */
int		destroy_game(t_s *s);
void	destroy_images(t_s *s);
void	destroy_map(t_m *m);

/* User IO func */
int		key_press(int keycode, t_s *sys);
int		key_release(int keycode, t_s *sys);
void	move(t_s *s, t_p *p);
void	collect(t_s *s);

/* Render func */
int		render(t_s *s);
void	render_swirl(t_s *s);
void	read_map(t_s *s, t_m *m, t_md **md);

/* Update Func */
void	update_input(t_s *sys);

/* Detect func */
t_b		dir_to_detect(int dir, t_p *p, t_md **md);

/* Map func */
char	*load_map(t_s *s, t_m *m, char *path);
t_b		create_map(t_m	*m);
/* + Define func */
int		define_type(t_m	*m, char c, int w, int h);
void	define_wall_type_1(t_md **md, int h, int w);
/* + Load func */
t_b		load_m_data(t_m *m, char *path);
t_b		load_m_image(t_s *s, t_m *m);
/* + Valid func */
t_b		valid_map(t_m *m, char *path);
/* + BFS func */
t_b		check_bfs_res(t_m *m, t_md **md);

/* Player func */
int		load_player(t_s *s, t_p *p);
void	update_player(t_s *s, t_p *p);

/* Util func */
t_b		new_image(t_s *s, t_img **target, char *p_path);
t_b		parse_path(char **target, char *path, int load, int pre);
void	*load_xpm(t_s *s, char *path, int x, int y);
t_b		load_xpm_t_img(t_s *s, t_img **target, int max, char *path);
t_b		load_xpm_dir(t_s *s, t_img **target, int max, char *path);
void	*load_action(t_p *p);

/* Additional Util func*/
char	*get_next_line(int fd);

#endif