/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:55 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:23:59 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format_u(unsigned int n)
{
	size_t	count;

	count = 0;
	if (print_nbr_base(&count, n, DECIMAL, DECIMAL_BASE) < 0)
		return (ERROR);
	return (count);
}
