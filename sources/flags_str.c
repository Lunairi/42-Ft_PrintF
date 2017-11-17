/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

/*
** Flags String Of Characters
** %s outputs in flags_str
** %c outputs in flags_char
*/

void	flags_char(va_list args)
{
	char *output;

	output = va_arg(args, char*);
	ft_putstr(output);
}

void	flags_str(va_list args)
{
	char *output;

	output = va_arg(args, char*);
	ft_putstr(output);
}