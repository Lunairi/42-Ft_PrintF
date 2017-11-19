/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_moreflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_j(va_list args, int *p, const char *str, int *i)
{
	*i = *i + 1;
	str[*i] == 'd' ? flags_intj(args, p) : 0;
	str[*i] == 'i' ? flags_intj(args, p) : 0;
	str[*i] == 'u' ? flags_uintj(args, p) : 0;
	str[*i] == 'o' ? flags_octj(args, p) : 0;
	str[*i] == 'x' ? flags_hexj(args, p) : 0;
	str[*i] == 'X' ? flags_uhexj(args, p) : 0;
}

// void	parse_z(va_list args, int *p, const char *str, int *i)
// {
// 	*i = *i + 2;
// 	str[*i] == 'd' ? flags_intz(args, p) : 0;
// 	str[*i] == 'i' ? flags_intz(args, p) : 0;
// 	str[*i] == 'u' ? flags_uintz(args, p) : 0;
// 	str[*i] == 'o' ? flags_octz(args, p) : 0;
// 	str[*i] == 'x' ? flags_hexz(args, p) : 0;
// 	str[*i] == 'X' ? flags_uhexz(args, p) : 0;
// }