/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:09:57 by serraoui          #+#    #+#             */
/*   Updated: 2023/12/01 20:30:04 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_args(const char *s, va_list *args, int *l, int pos)
{
	if (s[pos] == 'c')
		ft_putchar(va_arg(*args, int), l);
	else if (s[pos] == 'i' || s[pos] == 'd')
		ft_putnbr(va_arg(*args, int), l);
	else if (s[pos] == 'u')
		ft_print_base(va_arg(*args, unsigned int), "0123456789", 10, l);
	else if (s[pos] == 'x')
		ft_print_base(va_arg(*args, unsigned int), "0123456789abcdef", 16, l);
	else if (s[pos] == 'X')
		ft_print_base(va_arg(*args, unsigned int), "0123456789ABCDEF", 16, l);
	else if (s[pos] == 'p')
	{
		ft_putstr("0x", l);
		ft_print_base(va_arg(*args, unsigned long), "0123456789abcdef", 16, l);
	}
	else if (s[pos] == 's')
	{
		if (!ft_putstr(va_arg(*args, char *), l))
			ft_putstr("(null)", l);
	}
	else
		ft_putchar(s[pos], l);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			ft_printf_args(s, &args, &ret, ++i);
		else if (s[i] != '%')
			ft_putchar(s[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
