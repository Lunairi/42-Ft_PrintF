/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <math.h>
# include <stdarg.h>

# include "libft.h"

/*
** parse_flags.c
*/
void	parse_flags(int *i, const char *str, va_list args);

/*
** flags_int.c
*/
void	flags_int(va_list args);
void	flags_oct(va_list args);
void	flags_uint(va_list args);
void	flags_hex(va_list args);

/*
** flags_str.c
*/
void	flags_str(va_list args);
void	flags_char(va_list args);

#endif
