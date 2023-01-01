/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:14:38 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/16 04:13:24 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

void	fill_arr(t_push_swap **ps);
void	exit_on_error(int error_number, char *message);
void	quick_sort(int *arr, int low, int high);
void	*create_new(int number);
void	add_back(t_stack **stack, t_stack *new);
void	add_front(t_stack **stack, t_stack *new);
t_stack	*get_last(t_stack *stack);
int		get_stacksize(t_stack *stack);
void	fill_stack(t_push_swap **ps);
void	swap_num(int *a, int *b);
int		is_sorted(t_stack *stack);
int		iseq(char *s1, char *s2);
void	run(char *action, t_stack **a, t_stack **b);
void	push(t_stack **dest, t_stack **src);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
int		ft_putstr(char *str, int fd);
void	init_struct(t_push_swap **ps, int argc, char **argv);
void	short_sort(t_push_swap **ps);
void	big_sort(t_push_swap **ps);
void	set_value_from_index(t_push_swap **ps, t_stack *a);
void	sort_3(t_push_swap **ps);

#endif
