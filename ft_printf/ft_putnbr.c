/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:35:39 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/18 12:00:43 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	unsigned int	number;

	number = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-', len);
		number = n * -1;
	}
	if (number <= 9)
		ft_putchar(number + '0', len);
	if (number > 9)
	{
		ft_putnbr(number / 10, len);
		ft_putchar(number % 10 + '0', len);
	}
}
