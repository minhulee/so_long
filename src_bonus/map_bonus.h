/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:41:22 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:05:48 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "util_bonus.h"

# define MAP_MAX 5
# define MAP_PATH "./textures/map/"

# define MAP_WALL_MAX 13
# define MAP_WALL_PATH "./textures/map/wall/"

# define MAP_COLLECT_MAX 5
# define MAP_COLLECT_PATH "./textures/map/collect/"

# define MAP_ARROW_MAX 4
# define MAP_ARROW_PATH "./textures/map/arrow/"

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

typedef struct s_map
{
	int		w;
	int		h;
	t_v		start;
	int		time;
	int		frame;
	int		max_collected;
	int		collected;
	void	**map;
	void	**wall;
	void	**collect;
	void	**arrow;
	t_md	**md;
}	t_m;

#endif