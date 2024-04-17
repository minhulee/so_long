/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:37:48 by minhulee          #+#    #+#             */
/*   Updated: 2024/04/12 12:12:54 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

#define MARK_X 34
#define MARK_Y 16

typedef struct s_image
{
	void			*img;
	struct s_image	*next;
}	t_img;

typedef enum	s_bool
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

typedef struct	s_mark
{
	void	*mark;
	t_v		loc;
}	t_mark;

#endif