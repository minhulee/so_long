/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:49:39 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/23 12:58:27 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "./util.h"
# include "./map.h"
# include "./player.h"
# include "./zombie.h"

# define TITLE "Zombie Run !!"

# define IMAGE 131
# define SIZE 64

# define DUP 999
# define NON 998

# define FULL_X 1920
# define FULL_Y 1080

typedef struct s_swirl
{
	t_v	loc;
	t_b	t;
	int	r;
}	t_ss;

typedef struct s_system
{
	void	*mlx;
	void	*win;
	t_v		win_size;
	int		size;
	int		time;
	int		moved;
	int		loaded;
	int		z_num;
	t_p		player;
	t_m		map;
	t_zi	*zombies;
	t_zd	zd;
	void	*images[IMAGE];
	t_ss	swirl;
	t_b		clear;
	t_b		print;
}	t_s;

/* System func */
t_b		load_system(t_s *s);

/* Restart func */
void	init_swirl(t_ss *swirl);
int		end(t_s *s);
void	restart(t_s *sys);

/* + Error func */
void	exit_err(char *errstr);

/* Destroy func */
int		destroy_game(t_s *s);
void	destroy_images(t_s *s);
void	destroy_map(t_m *m);
void	destroy_player(t_p *p);

/* event func */
int		key_press(int keycode, t_s *sys);
int		key_release(int keycode, t_s *sys);
void	input(t_s *s);

/* Pyshic func */
void	collect(t_s *s);
void	pmove(t_s *s, t_p *p, int sp);
void	zmove(t_zi *zi, int sp);

/* Detect & Collision func */
void	player_to_detect(t_s *s, int dir, t_p *p, t_md **md);
void	zombie_to_detect(t_s *s, int dir, t_zi *zi, t_md **md);
void	collision(t_s *s, t_v ploc, t_zi *zombies);

/* Detect func */
int		detect_front(t_md **target, t_v loc, int sp, t_md **md);
int		detect_left(t_md **target, t_v loc, int sp, t_md **md);
int		detect_right(t_md **target, t_v loc, int sp, t_md **md);
int		detect_back(t_md **target, t_v loc, int sp, t_md **md);

/* Update func */
void	update_time(t_s *s);
void	update_frame(t_s *s, t_p *p, t_m *m);

/* Render func */
int		render(t_s *s);
void	mrender(t_s *s, t_m *m, t_md **md);
void	prender(t_s *s, t_p *p);
void	zrender(t_s *s, t_zi *z);
void	srender(t_s *s);

/* Map func */
char	*load_map(t_s *s, t_m *m, char *path);
t_b		create_map(t_m	*m);
/* + Define func */
int		define_type(t_m	*m, char c, int w, int h);
void	define_wall_type_1(t_md **md, int h, int w);
/* + Load func */
t_b		load_m_data(t_s *s, t_m *m, char *path);
t_b		load_m_image(t_s *s, t_m *m);
/* + Valid func */
t_b		valid_map(t_m *m, char *path);
/* + BFS func */
t_b		check_bfs_res(t_m *m, t_md **md);

/* Player func */
t_b		load_player(t_s *s, t_p *p);

/* Zombie func */
t_b		load_zombie(t_s *s, t_zd *zd);
void	spawn_zombie(t_s *s, t_zi *zombies);

/* Util func */
void	sort_zombie_to_y(t_s *s, t_zi *zombies);
char	*parse_path(char *path, int num, t_b deps);
void	***load_xpmss(t_s *s, char *path, int deps, int max);
void	**load_xpms(t_s *s, char *path, int max);
void	*load_xpm(t_s *s, char *path, int size);
void	*free_xpmss(void ***xpmss, int deps);
void	*free_xpms(void **xpms);

/* Additional Util func*/
char	*get_next_line(int fd);

#endif