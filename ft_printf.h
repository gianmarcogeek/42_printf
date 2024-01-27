/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:19 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/27 17:23:11 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long long n, int fd);
int		ft_putnbr_base(long nbr, char *base);
int		ft_printf(const char *str, ...);

#endif
