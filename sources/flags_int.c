/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

/*
** Flags Signed Decimal Integers
** %d and %i outputs in flags_int
** %o outputs in flags_oct
** %u outputs in flags_uint
** %x outputs in flags_hex
*/

void	flags_hex(va_list args)
{
	unsigned int output;

	output = va_arg(args, unsigned int);
	ft_puthex(output);
}

void	flags_oct(va_list args)
{
	unsigned int output;

	output = va_arg(args, unsigned int);
	ft_putoct(output);
}

void	flags_uint(va_list args)
{
	unsigned int output;

	output = va_arg(args, unsigned int);
	ft_putunbr(output);
}

void	flags_int(va_list args)
{
	int output;

	output = va_arg(args, int);
	ft_putnbr(output);
}