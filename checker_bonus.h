/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serraoui <serraoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:21:57 by serraoui          #+#    #+#             */
/*   Updated: 2024/02/19 14:21:58 by serraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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
