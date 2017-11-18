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
** libft functions: ft_putchar, ft_putstr
*/

void	flags_adr(va_list args, int *p)
{
	// int a;
 //  unsigned int uip = (unsigned int) ((void*) &a);
 //  printf("address of a = 0x%x", uip);
 //  printf("\naddress of a = %p", uip);
  
	void *output;
	unsigned int address;

	output = va_arg(args, void*);
	address = (unsigned int)(output);
	write(1, "0x", 2);
	*p = *p + 2;
	ft_puthex(address, p);
}
