/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:10:25 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/17 15:31:27 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"
# include "get_next_line.h"

int	read_ops(t_stack **a, t_stack **b);
int	push_ops(t_stack **a, t_stack **b, char *s);
int	rev_rot_ops(t_stack **a, t_stack **b, char *s);
int	swap_ops(t_stack **a, t_stack **b, char *s);
int	rot_ops(t_stack **a, t_stack **b, char *s);

#endif
