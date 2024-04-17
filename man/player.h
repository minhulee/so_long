/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:11:07 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/16 08:03:20 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "map.h"
#include "./util.h"

#define P_PATH "./textures/player/"

#define P_IDLE_MAX 2
#define P_RUN_MAX 4
#define P_DEATH_MAX 4
#define P_XPM_MAX 4 * (P_IDLE_MAX + P_RUN_MAX + P_DEATH_MAX)

typedef enum e_player_action
{
	IDLE = 0,
	RUN,
	DEATH,
}	t_pa;

typedef enum s_direction
{
	FRONT = 0,
	LEFT,
	RIGHT,
	BACK,
}	t_dir;

typedef struct s_player
{
	t_v		loc;
	t_dir	dir;
	t_pa	cur;
	int		time;
	int		sp;
	t_b		input[5];
	t_b		deathd;
	t_mark	mark;
	t_md	*target;
	t_img	*idle[4];
	t_img	*run[4];
	t_img	*death[4];
}	t_p;

#endif