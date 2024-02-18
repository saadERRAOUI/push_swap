/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:17:04 by serraoui          #+#    #+#             */
/*   Updated: 2023/11/18 12:03:26 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_print_base(unsigned long n, const char *chars, int base, int *len);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s, int *len);

#endif
