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
# include <stdint.h>
# include <inttypes.h>

# include "libft.h"

/*
** parse_flags.c
*/
void	parse_flags(int *i, const char *str, va_list args, int *p);

/*
** flags_int.c
*/
void	flags_int(va_list args, int *p);
void	flags_oct(va_list args, int *p);
void	flags_uint(va_list args, int *p);
void	flags_hex(va_list args, int *p);
void	flags_uhex(va_list args, int *p);

/*
** flags_adr.c
*/
void	flags_adr(va_list args, int *p);
void	flags_per(va_list args, int *p);

/*
** flags_str.c
*/
void	flags_str(va_list args, int *p);
void	flags_char(va_list args, int *p);

/*
** flags_spc.
*/

void	flags_ws(va_list args, int *p, const char *str, int *i);
void	flags_plus(va_list args, int *p, const char *str, int *i);
void	flags_hash(va_list args, int *p, const char *str, int *i);

#endif
