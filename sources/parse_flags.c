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
** Completed: s d i o u x c X %% p + space #
** In Progress: precision 0 hh h ll j z l(SDOUC)
*/

/*
** This function is using ternary to help parse the current char that
** was passed from the printf function previously so the flag/modifier
** can be performed in the respective flags_ function
*/


void	ft_putspace(int s, int size, int *p)
{
	int count;

	count = 0;
	if (s > size)
	{
		count = s - size;
		while(--count >= 0)
		{
			write(1, " ", 1);
			*p = *p + 1;
		}
	}
}

void	flag_ralign(const char *str, va_list args, int align, int *i, int *p)
{
	void *check;
	unsigned long address;

	check = va_arg(args, void*);
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		ft_putspace(align, ft_numlen((int)check), p);
		ft_putnbrf((int)check, p);
	}
	if (str[*i] == 'u' || str[*i] == 'o' || str[*i] == 'x' || str[*i] == 'X')
	{
		ft_putspace(align, ft_numulen((unsigned int)check), p);
		ft_putnbrf((unsigned int)check, p);
	}
	if (str[*i] == 's')
	{
		ft_putspace(align, ft_strlen((char*)check), p);
		ft_putstrf((char*)check, p);
	}
	if (str[*i] == 'c' || str[*i] == '%')
	{
		ft_putspace(align, 1, p);
		*p = *p + 1;
		if (str[*i] == 'c')
			ft_putchar((char)check);
		else
			write(1, "%", 1);
	}
	if (str[*i] == 'p')
	{
		ft_putspace(align, 14, p);
		address = (unsigned long)(check);
		write(1, "0x7ff", 5);
		*p = *p + 5;
		ft_putadr(address, p);
	}
}

void	parse_rightalign(int *i, const char *str, va_list args, int *p) // has error need fix, printing some extra stuff somewhere
{
	int count;
	int align;

	count = *p; 
	align = 0;
	while (str[*i] >= '0'  && str[*i] <= '9')
	{
		if (str[*i] >= '0'  && str[*i] <= '9')
			align = align * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	flag_ralign(str, args, align, i, p);
}

void	parse_leftalign(int *i, const char *str, va_list args, int *p) // has error need fix, printing some extra stuff somewhere
{
	int count;
	int align;
	int check;

	count = *p; 
	align = 0;
	check = 0;
	*i = *i + 1;
	while (str[*i] >= '0'  && str[*i] <= '9')
	{
		align = align * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	*i = *i - 1;
	parse_flags(i, str, args, p);
	if (align > (*p - count))
	{
		check = align - (*p - count);
		while(--check >= 0)
		{
			write(1, " ", 1);
			*p = *p + 1;
		}
	}
}

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
	str[*i] == '%' ? flags_per(args, p) : 0;
	str[*i] == '+' ? flags_plus(args, p, str, i) : 0;
	str[*i] == '#' ? flags_hash(args, p, str, i) : 0;
	str[*i] >= '0' && str[*i] <= '9' ? parse_rightalign(i, str, args, p) : 0;
	str[*i] == '-' ? parse_leftalign(i, str, args, p) : 0;
	str[*i] == ' ' ? flags_ws(args, p, str, i) : 0;
}
