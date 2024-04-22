/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:11:07 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:05:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "./map_bonus.h"
# include "./util_bonus.h"

# define PLAYER_MARK_MAX 2
# define PLAYER_MARK_PATH "./textures/player/"

# define PLAYER_IDLE_MAX 2
# define PLAYER_IDLE_PATH "./textures/player/idle/"

# define PLAYER_RUN_MAX 4
# define PLAYER_RUN_PATH "./textures/player/run/"

# define PLAYER_DEATH_MAX 4
# define PLAYER_DEATH_PATH "./textures/player/death/"

typedef struct s_player
{
	t_v		loc;
	t_dir	dir;
	t_a		action;
	int		sp;
	int		time;
	int		frame;
	void	**mark;
	void	***idle;
	void	***run;
	void	***death;
	t_b		input[4];
	t_md	*target;
}	t_p;

#endif