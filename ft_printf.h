/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:17:04 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/12 23:50:31 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_print_base(unsigned long long n, const char *c, int b, int *l);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
int		ft_printf(const char *s, ...);
void	ft_putstr(char *s, int *len);

#endif
