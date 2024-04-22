/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:30:05 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:05:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_BONUS_H
# define ZOMBIE_BONUS_H

# include "map_bonus.h"
# include "util_bonus.h"

# define ZOMBIE_MARK_MAX 2
# define ZOMBIE_MARK_PATH "./textures/zombie/"

# define ZOMBIE_IDLE_MAX 5
# define ZOMBIE_IDLE_PATH "./textures/zombie/idle/"

# define ZOMBIE_RUN_MAX 10
# define ZOMBIE_RUN_PATH "./textures/zombie/run/"

typedef struct s_zombie_info
{
	t_v		start;
	t_v		loc;
	t_dir	dir;
	t_a		action;
	int		ctime;
	int		time;
	int		frame;
	t_md	*target;
}	t_zi;

typedef struct s_zombie_data
{
	int		sp;
	void	**mark;
	void	***idle;
	void	***run;
}	t_zd;

#endif