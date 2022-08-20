/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 20:18:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/08/18 20:26:18 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h> 
# include "../../libft/include/libft.h"

int	ft_printf(const char *str, ...);
int	ft_unsigned_int(unsigned int n);
int	print_persent(void);
int	print_str(char *str);
int	print_char(int n);
int	print_nub(int n);
int	print_hex(unsigned int num, char fmt);
int	print_pointer(unsigned long long n);

#endif
