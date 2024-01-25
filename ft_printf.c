/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:03:37 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/25 19:31:31 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/* TODO
	makefile that compile printf.c and launch make inside the libft
	putptr
	puthex
*/

int	ft_format(va_list args, const char format)
{
	int len;

	len = 0;
		if (format == '%')
			len += ft_putchar_fd('%', 1);
		else if (format == 'c')
			len += ft_putchar_fd(va_arg(args, int), 1);
		else if (format == 's')
			len += ft_putstr_fd(va_arg(args, char *), 1);
		else if (format == 'd' || format == 'i')
			len += ft_putnbr_fd(va_arg(args, int), 1);
		/*else if (format == 'p')
			len += ft_putptr(va_arg(args, unsigned long long));*/
		else if (format == 'u')
			len += ft_putnbr_fd(va_arg(args, unsigned int), 1);
		/*else if (format == 'x' || format == 'X')
			len += ft_puthex(va_arg(args, unsigned int));*/
		return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	len;

	va_start(args, str);
	len = 0;
	while(*str)
	{
		if(*str == '%')
		{
			len += ft_format(args, *(++str));
			str++;
		}
		else
		{
			len += ft_putchar_fd(*str, 1);
			str++;
		}
	}
	va_end (args);
	return (len);
}

#include <stdio.h>

int main()
{
	int len = ft_printf("|Test, %% %c %s %d %u|", 'x', "gpuscedd", 2147483648, 2147483648);
	ft_printf("	[%d]", len);
}