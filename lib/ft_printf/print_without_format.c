/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_without_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:17:56 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/03 17:59:50 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_without_format(char c)
{
	if (write(1, &c, 1) < 0)
		return (ERROR);
	return (TRUE);
}
