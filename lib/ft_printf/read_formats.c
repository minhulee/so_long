/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_formats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 08:38:21 by minhulee          #+#    #+#             */
/*   Updated: 2023/12/05 14:46:01 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	next_format(char *f)
{
	size_t	i;
	size_t	cursor;

	i = 1;
	while (f[i])
	{
		cursor = 0;
		while (cursor < SPEC_COUNT)
		{
			if (f[i] == SPECIFIER[cursor])
				return (i + 1);
			cursor++;
		}
		i++;
	}
	return (ERROR);
}

int	read_fomat(char *f, size_t *n, size_t c, va_list args)
{
	int	count;

	*n = next_format(f + c);
	if (*n < 0)
		return (ERROR);
	count = print_format(f[c + *n - 1], args);
	if (count < 0)
		return (ERROR);
	return (count);
}

int	read_formats(char *f, va_list args)
{
	int		total;
	int		count;
	size_t	next;
	size_t	cursor;

	total = 0;
	cursor = 0;
	while (f[cursor])
	{
		if (f[cursor] == '%')
		{
			count = read_fomat(f, &next, cursor, args);
			if (count < 0)
				return (ERROR);
			total += count;
			cursor += next;
			continue ;
		}
		if (print_without_format(f[cursor]) < 0)
			return (ERROR);
		total++;
		cursor++;
	}
	return (total);
}
