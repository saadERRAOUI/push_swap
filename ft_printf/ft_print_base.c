/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:41:05 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/17 22:52:42 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base(unsigned long n, const char *chars, int base, int *len)
{
	if (n >= (unsigned long)base)
		ft_print_base(n / base, chars, base, len);
	ft_putchar(chars[n % base], len);
}
