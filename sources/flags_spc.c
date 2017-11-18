/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_spc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Flags address
** %p outputs in flags_adr
** %% outputs in flags_per
** libft functions: ft_puthex
*/

void	flags_ws(va_list args, int *p, const char *str, int *i)
{
	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		*p = *p + 1;
		write(1, " ", 1);
	}
	parse_flags(i, str, args, p);
}

void	flags_plus(va_list args, int *p, const char *str, int *i)
{
	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		*p = *p + 1;
		write(1, "+", 1);
	}
	else if (str[*i + 1] == 'h' && 
		(str[*i + 2] == 'd' || str[*i + 2] == 'i'))
	{
		*i = *i + 1;
		*p = *p + 1;
		write(1, "+", 1);	
	}
	parse_flags(i, str, args, p);
}

void	flags_hash(va_list args, int *p, const char *str, int *i)
{
	// if (str[*i + 1] == 'o')
	// {
	// 	*p = *p + 1;
	// 	write(1, "0", 1);
	// }
	if (str[*i + 1] == 'x')
	{
		*p = *p + 2;
		write(1, "0x", 2);
	}
	else if (str[*i + 1] == 'X')
	{
		*p = *p + 2;
		write(1, "0X", 2);
	}
	parse_flags(i, str, args, p);
}
