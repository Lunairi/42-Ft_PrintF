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

#include "printf.h"

/*
** You have to manage the following conversions: SDOUC (ls ld lo lu lc)
** • You must manage the flags #0-+ and space
** • You must manage the minimum field-width
** • You must manage the flags hh, h, l, ll, j, et z.
*/

/*
** Completed: s d i o u x c X
** In Progress: p %% precision
*/

/*
** This function is using ternary to help parse the current char that
** was passed from the printf function previously so the flag/modifier
** can be performed in the respective flags_ function
*/

void	parse_flags(int *i, const char *str, va_list args, int *p)
{
	*i = *i + 1;
	str[*i] == 'd' ? flags_int(args, p) : 0;
	str[*i] == 'i' ? flags_int(args, p) : 0;
	str[*i] == 'u' ? flags_uint(args, p) : 0;
	str[*i] == 'o' ? flags_oct(args, p) : 0;
	str[*i] == 's' ? flags_str(args, p) : 0;
	str[*i] == 'x' ? flags_hex(args, p) : 0;
	str[*i] == 'X' ? flags_uhex(args, p) : 0;
	str[*i] == 'c' ? flags_char(args, p) : 0;
	str[*i] == 'p' ? flags_adr(args, p) : 0;
	str[*i] == '%' ? write(1, "%", 1) : 0;
}
