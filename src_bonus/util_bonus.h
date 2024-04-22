/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:37:48 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/22 17:05:44 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# define DIRECTION 4

typedef enum s_bool
{
	FAIL = -1,
	FALSE,
	TRUE
}	t_b;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_v;

typedef enum s_direction
{
	FRONT = 0,
	LEFT,
	RIGHT,
	BACK,
}	t_dir;

typedef enum e_player_action
{
	IDLE = 0,
	RUN,
	DEATH,
}	t_a;

#endif