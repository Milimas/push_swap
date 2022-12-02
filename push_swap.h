/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:37:06 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/28 14:47:26 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

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
	int		number;
	struct s_stack	*next;
} t_stack;

typedef struct s_arr
{
	int		*a;
	int		*head;
	size_t	size;
} t_arr;

void	quick_sort(int *arr, int low, int high);

void	fill_arr(t_arr **arr, int argc, char **argv);

void	*create_new(int number);
t_stack	*get_last(t_stack *stack);
void	add_back(t_stack **stack, t_stack *new);
void	add_front(t_stack **stack, t_stack *new);
void	swap_num(int *a, int *b);
int		iseq(char *s1, char *s2);
size_t	ft_putchar(int fd, char *c);
int		ft_isdigits(char *str);
void	ft_error(void *);
void	swap_num(int *a, int *b);

void	run(char *action, t_stack **a, t_stack **b);

// utils
void	swap(t_stack **a);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
//---------
void	fill_stack(t_stack **stack, int argc, char **argv);
int		is_sorted(t_stack *stack);
void	print_stack(t_stack *stack);
void	print_arr(int *arr, int size);
void	free_arr(t_arr *arr);
void	free_stack(t_stack *stack);
int		get_stacksize(t_stack *stack);
int		get_index(t_stack *stack, int number);
int		get_arr_index(t_arr *arr, int number);
int		get_rot(t_stack *stack, int number);
int		is_inchunk(int *arr, int num, int size);
// void	load_back(t_stack **stack_a, t_stack **stack_b, t_arr *arr);
int		get_last_inchunk(t_stack *stack, t_arr *arr);
// void	load_chunks(t_stack **stack_a, t_stack **stack_b, t_arr *arr);

#endif
