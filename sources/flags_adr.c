/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_adr.c                                        :+:      :+:    :+:   */
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

void	ft_putadr(unsigned long n, int *p)
{
	if (n > 15)
	{
		ft_puthex((n / 16), p);
		ft_puthex((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
	else
	{
		*p = *p + 1;
		n == 10 ? ft_putchar('a') : 0;
		n == 11 ? ft_putchar('b') : 0;
		n == 12 ? ft_putchar('c') : 0;
		n == 13 ? ft_putchar('d') : 0;
		n == 14 ? ft_putchar('e') : 0;
		n == 15 ? ft_putchar('f') : 0;
	}
}


void	flags_adr(va_list args, int *p)
{
	void *output;
	unsigned long address;

	output = va_arg(args, void*);
	address = (unsigned long)(output);
	write(1, "0x7ff", 5);
	*p = *p + 5;
	ft_putadr(address, p);
}

void	flags_per(va_list args, int *p)
{
	*p = *p + 1;
	write(1, "%", 1);
}
