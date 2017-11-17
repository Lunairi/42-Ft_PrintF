/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

/*
** You have to manage the following conversions: SpDOUXC
** • You must manage %%
** • You must manage the flags #0-+ and space
** • You must manage the minimum field-width
** • You must manage the precision
** • You must manage the flags hh, h, l, ll, j, et z.
*/

/*
** Completed: s d i o u
** In Progress: x c
*/

void	parse_flags(int *i, const char *str, va_list args)
{
	*i = *i + 1;
	if (str[*i] == 'd' || str[*i] == 'i')
		flags_int(args);
	else if (str[*i] == 'u')
		flags_uint(args);
	else if (str[*i] == 'o')
		flags_oct(args);
	else if (str[*i] == 's')
		flags_str(args);
}
