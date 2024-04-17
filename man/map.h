/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:41:22 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/17 11:41:42 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "util.h"

# define M_PATH "./textures/map/"
# define W_PATH "./textures/map/wall/"

typedef enum e_tile
{
	N = -1,
	W,
	P,
	S,
	C,
	E
}	t_t;

typedef enum e_wall_type
{
	D = 0,
	T,
	L,
	R,
	B,
	TL,
	TR,
	BL,
	BR,
	BOTH_H,
	BOTH_W,
	BOTH_B,
	CT,
	UDEF
}	t_wt;

typedef enum e_collect_type
{
	CLOSE = 0,
	OPEN = 1
}	t_ct;

typedef struct s_map_data
{
	t_t		t;
	t_wt	wt;
	t_b		visited;
}	t_md;

typedef struct s_map_img
{
	void	*g;
	void	*b;
	void	*e;
}	t_mi;

typedef struct s_wall_img
{
	void	*d;
	void	*t;
	void	*l;
	void	*r;
	void	*b;
	void	*tl;
	void	*tr;
	void	*bl;
	void	*br;
	void	*bh;
	void	*bw;
	void	*bb;
	void	*ct;
}	t_wi;

typedef struct s_map
{
	int		w;
	int		h;
	t_v		start;
	int		time;
	int		max_collected;
	int		collected;
	void	*m_img[5];
	void	*w_img[13];
	t_img	*collect;
	t_img	*arrow;
	t_md	**md;
}	t_m;

#endif