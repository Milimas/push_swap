/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:14:38 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/16 09:00:48 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;
	int		*arr;
	int		bsplit;
	int		size;
}	t_push_swap;

void	exit_on_error(int error_number, char *message);
void	quick_sort(int *arr, int low, int high);
void	fill_stack(t_push_swap **ps);
int		is_sorted(t_stack *stack);
int		iseq(char *s1, char *s2);
void	push(t_stack **dest, t_stack **src);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
int		ft_putstr(char *str, int fd);
void	init_struct(t_push_swap **ps, int argc, char **argv);

#endif
