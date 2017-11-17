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
** This function will use a ellipsis prototype to grab the initial input
** when calling printf. Afterwards it'll start reading the string and 
** begin outputting as necessary, if a flag is reached it'll call
** the parse_flags function to help perform necessary edits
*/

int		ft_printf(const char *str, ...)
{
	va_list args;
	char *input;
	int i;

	i = -1;
	va_start(args, str);
	input = va_arg(args, char*);
	while(str[++i] != '\0')
	{
		//if(str[i] == '%')
			// check flag
		write(1, &str[i], 1);
	}
	printf("%s", input);
	
	va_end(args);
	return 0;
}

/*
** Main to test the functionality
*/

int		main(int ac, char **av)
{
	ft_printf("test", "test2", "test3", "test4");
	// printf("Test %d", 25);
	return 0;
}