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

# include "printf.h"



/*
** • This function will use a ellipsis prototype to grab the initial input
** when calling printf. Afterwards it'll start reading the string and 
** begin outputting as necessary, if a flag is reached it'll call
** the parse_flags function to help perform necessary edits.
** • Int i is used to track the current str that was passed being read.
** By passing its address I can skip outputting the flags and output
** it elsewhere in my other functions. 
*/

int		ft_printf(const char *str, ...)
{
	va_list args;
	// void *input;
	int i;

	i = -1;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			// input = va_arg(args, char*);
			parse_flags(&i, str, args);
		}
		else
			write(1, &str[i], 1);
	}
	// printf("%s", input);
	va_end(args);
	return 0;
}

/*
** Main to test the functionality
*/

int		main(int ac, char **av)
{
	ft_printf("test %d %i %s %o %u", 25, 35, "test4", 12354, -2147483649);
	printf("\ntest %d %i %s %o %u", 25, 35, "test4", 12354, -2147483649);
	// printf("Test %d", 25);
	return 0;
}