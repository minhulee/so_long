/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:38:55 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:23:39 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(size_t *count, long *n)
{
	if (*n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (ERROR);
		*n *= -1;
		(*count)++;
	}
	return (TRUE);
}

int	print_format_di(long n)
{
	size_t	count;

	count = 0;
	if (print_sign(&count, &n) < 0)
		return (ERROR);
	if (print_nbr_base(&count, n, DECIMAL, DECIMAL_BASE) < 0)
		return (ERROR);
	return (count);
}
