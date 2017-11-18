/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** • This function will use a ellipsis prototype to grab the initial input
** when calling printf. Afterwards it'll start reading the string and
** begin outputting as necessary, if a flag is reached it'll call
** the parse_flags function to help perform necessary edits.
** • Int i is used to track the current str that was passed being read.
** By passing its address I can skip outputting the flags and output
** it elsewhere in my other functions. P is used to track how much bytes
** are being printed, the addressed is passed to keep track.
*/

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		p;

	i = -1;
	p = 0;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
			parse_flags(&i, str, args, &p);
		else
			write(1, &str[i], 1);
	}
	va_end(args);
	return (p);
}

// /*
// ** Main to test the functionality
// */

int		main(int ac, char **av)
{
	void *a;
	long b = 9;
	char d = 5;
	short c = 35000;
	unsigned short f = 999;
	// a = 0
	ft_printf("test |%+i| |%+d| |%+4i| |%+-4i| |%+04d| |%5i|", 42, 42, 42, 42, 42, -42);
	printf("\ntest |%+i| |%+d| |%+4i| |%+-4i| |%+04d| |%5i|", 42, 42, 42, 42, 42, -42);
// write(1, "\n", 1);
	// ft_printf("%X", ft_printf("%d", 2));
	// write(1, "\n", 1);
	// printf("%X", printf("%d", 2));
	// printf("Test %d", 25);
	return (0);
}
