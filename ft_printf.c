/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:03:37 by gpuscedd          #+#    #+#             */
/*   Updated: 2024/01/25 17:37:55 by gpuscedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/* TODO
	sub functions of ft_format
*/

void	ft_format(va_list args, const char format, int *len)
{
		if (format == '%')
			len += ft_putchar('%');
		/*else if (format == 'c')
			len += ft_putchar(va_arg(args, int));
		else if (format == 's')
			len += ft_putstr(va_arg(args, char *));
		else if (format == 'd' || format == 'i')
			len += ft_putnbr(va_arg(args, int));
		else if (format == 'p')
			len += ft_putptr(va_arg(args, unsigned long long));
		else if (format == 'u')
			len += ft_putunsigned(va_arg(args, unsigned int));
		else if (format == 'x' || format == 'X')
			len += ft_puthex(va_arg(args, unsigned int));*/
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
			ft_format(args, *(str + 1), &len);
			str++;
		}
		else
		{
			len += ft_putchar(*str);
			str++;
		}
	}
	va_end (args);
	return (len);
}