/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:19:41 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/27 20:27:42 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr(unsigned long long nbr, unsigned long long base_val, char *symbols)
{
	int len;

	len = 0;
	if (nbr >= base_val)
		len += print_nbr((nbr/base_val), base_val, symbols);
	len += ft_putchar_fd(symbols[nbr%base_val], 1);
	return (len);
}
int	ft_putptr(unsigned long long address)
{
	char *base;
	unsigned long long base_val;
	int	len;
	
	base = "0123456789abcdef";
	base_val = 0;
	len = 0;
	
	if (address == 0)
	{
		len += ft_putstr_fd("(nil)", 1);
		return (len);
	}
	len += ft_putstr_fd("0x", 1);
	while(base[base_val])
	{
		if(base[base_val] == '+' || base[base_val] == '-')
			return (0);
		++base_val;
	}
	len += print_nbr(address, base_val, base);
	return (len);
}

