/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:01:58 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/27 10:10:28 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *second;

	if (!*stack || !(*stack)->next)
		return ;
	second = (*stack)->next;
	//(*stack)->next = second->next;
	//second->next = *stack;
	//*stack = second;
	swap_num(&(*stack)->number, &(*stack)->next->number);
}

void	push(t_stack **dest, t_stack **src)
{
	t_stack *tmp;

	if (!*src)
		return ;
	tmp = *src;
	if ((*src)->next)
	{
		*src = (*src)->next;
		tmp->next = NULL;
	}
	else 
		*src = NULL;
	add_front(dest, tmp);
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	add_back(stack, tmp);
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next)
		if (before_last->next->next)
			before_last = before_last->next;
		else
			break ;
	before_last->next->next = *stack;
	*stack = before_last->next;
	before_last->next = NULL;
}

//----------------------------------------------------

#include "push_swap.h"

// #define CHUNK 40

// void	print_stack(t_stack *stack)
// {
// 	printf("[ ");
// 	while(stack)
// 	{
// 		printf("%d, ", stack->number);
// 		stack = stack->next;
// 	}
// 	printf(" ]");
// }

// void	print_arr(int *arr, int size)
// {
// 	int *a;

// 	printf("[ ");
// 	if (arr)
// 	{
// 		a = arr;
// 		while(size--)
// 			printf("%d, ", *a++);
// 	}
// 	printf(" ]\n");
// }

// void	free_arr(t_arr *arr)
// {
// 	if (arr && arr->a)
// 		free(arr->head);
// 		free(arr);
// 		arr = NULL;
// }

// int	is_sorted(t_stack *stack)
// {
// 	while(stack && stack->next)
// 		if (stack->number > stack->next->number)
// 			return (0);
// 		else
// 			stack = stack->next;
// 	return (1);
// }

// void	free_stack(t_stack *stack)
// {
// 	t_stack	*next;

// 	while (stack)
// 	{
// 		next = stack->next;
// 		free(stack);
// 		stack = next;
// 	}
// 	stack = NULL;
// }

// int		get_stacksize(t_stack *stack)
// {
// 	int	size;

// 	size = 0;
// 	while (stack)
// 	{
// 		stack = stack->next;
// 		size++;
// 	}
// 	return (size);
// }

// int		get_index(t_stack *stack, int number)
// {
// 	int i;

// 	i = 0;
// 	while (stack)
// 	{
// 		if (stack->number == number)
// 			return (i);
// 		i++;
// 		stack = stack->next;
// 	}
// 	return (-1);
// }

// int	get_arr_index(t_arr *arr, int number)
// {
// 	int size;

// 	size = arr->size;
// 	while (size >= 0)
// 	{
// 		if (arr->a[size-- - 1] == number)
// 			return (size);
// 	}
// 	return (-1);
// }

// int		get_rot(t_stack *stack, int number)
// {
// 	int index;
// 	int size;

// 	index = get_index(stack, number);
// 	size = get_stacksize(stack);
//    	if (index <= size / 2 && index >= 0)
// 		return (1);
// 	if (index > size / 2 && index >= 0)
// 		return (-1);
// 	return (0);
// }

// int		is_inchunk(int *arr, int num, int size)
// {
// 	if (size > CHUNK)
// 		size = CHUNK;
// 	while (size > 0)
// 		if (arr[--size] == num)
// 			return (1);
// 	return (0);
// }

// int		get_middle_inchunk(t_arr *arr)
// {
// 	int size;

// 	size = arr->size;
// 	if (size > CHUNK)
// 		size = CHUNK;
// 	return (arr->a[size / 2]);
// }

// void	load_back(t_stack **stack_a, t_stack **stack_b, t_arr *arr)
// {
// 	int size;
// 	int rot;
	
// 	size = get_stacksize(*stack_b);
// 	while (*stack_b && size >= 0)
// 	{
// 		while (size >= 0 && (*stack_b)->number != arr->head[size - 1] && get_index(*stack_b, arr->head[size - 1]) != -1)
// 		{
// 			rot = get_rot(*stack_b, arr->head[size - 1]);
// 			if (rot == -1)
// 			{
// 				// if ((*stack_b)->next
// 				// 		&& (*stack_b)->next->number > (*stack_b)->number)
// 				// 	run(SB, stack_a, stack_b);
// 				run(RRB, stack_a, stack_b);
// 			}
// 			else if (rot == 1)
// 				run(RB, stack_a, stack_b);
// 		}
// 		if (size >= 0 && (*stack_b)->number == arr->head[size - 1])
// 		{
// 			size--;
// 			run(PA, stack_a, stack_b);
// 		}
// 	}
// }

// int		get_last_inchunk(t_stack *stack, t_arr *arr)
// {
// 	int	index;
// 	int last;
// 	int first;

// 	index = 0;
// 	last = -1;
// 	first = -1;
// 	while (stack)
// 	{
// 		if (is_inchunk(arr->a, stack->number, arr->size))
// 		{
// 			if (first == -1)
// 				first = index;
// 			last = index;
// 		}
// 		index++;
// 		stack = stack->next;
// 	}
// 	if (last == -1 || (first != -1 && first < (int)arr->size - last))
// 		return (first);
// 	if (first == -1 || (last != -1 && (int)arr->size - last < first))
// 		return (last);
// 	return (-1);
// }

// void	load_chunks(t_stack **stack_a, t_stack **stack_b, t_arr *arr)
// {
// 	int chunk;
// 	int rot;
// 	int index;

// 	chunk = CHUNK;
// 	index = -1;
// 	while (*stack_a)
// 	{
// 		if (chunk == 0)
// 		{
// 			chunk = CHUNK;
// 			arr->a += chunk;
// 			arr->size -= chunk;
// 			if ((int)arr->size < chunk)
// 				chunk = arr->size;
// 		}
// 		if ((*stack_a)->next && *stack_b && (*stack_b)->next
// 				&& (*stack_b)->next->number > (*stack_b)->number
// 				&& (*stack_a)->number > (*stack_a)->next->number)
// 			run(SS, stack_a, stack_b);
// 		if (is_inchunk(arr->a, (*stack_a)->number, arr->size))
// 		{
// 			chunk--;
// 			run(PB, stack_a, stack_b);
// 		}
// 		else
// 		{
// 			rot = 1;
// 			index = get_last_inchunk(*stack_a, arr);
// 			if (index > (int)arr->size / 2)
// 			{
// 				rot = -1;
// 			}
// 			if (rot == -1)
// 			{
// 				// if (*stack_b && index != -1
// 				// 	&& arr->a[index] > (*stack_b)->number
// 				// 	&& is_inchunk(arr->a, get_last(*stack_b)->number, arr->size))
// 				// 	run(RRR, stack_a, stack_b);
// 				// else
// 					run(RRA, stack_a, stack_b);
// 			}
// 			else if (rot == 1)
// 			{
// 				// if (*stack_b && (*stack_b)->next && index != -1
// 				// 	&& arr->a[index] < (*stack_b)->number
// 				// 	&& is_inchunk(arr->a, (*stack_b)->next->number, arr->size))
// 				// 	run(RR, stack_a, stack_b);
// 				// else
// 					run(RA, stack_a, stack_b);
// 			}
// 		}
// 	}
// }


// void	load_chunks2(t_stack **stack_a, t_stack **stack_b, t_arr *arr)
// {
// 	int chunk;
// 	int rot;
// 	int index;

// 	chunk = CHUNK;
// 	index = -1;
// 	while (*stack_a)
// 	{
// 		if (chunk == 0)
// 		{
// 			chunk = CHUNK;
// 			arr->a += chunk;
// 			arr->size -= chunk;
// 			if ((int)arr->size < chunk)
// 				chunk = arr->size;
// 		}
// 		if (is_inchunk(arr->a, (*stack_a)->number, arr->size))
// 		{
// 			chunk--;
// 			run(PB, stack_a, stack_b);
// 			if ((*stack_b)->number < get_middle_inchunk(arr))
// 				run(RB, stack_a, stack_b);
// 		}
// 		else
// 		{
// 			rot = 1;
// 			index = get_last_inchunk(*stack_a, arr);
// 			if (index > (int)arr->size / 2)
// 			{
// 				rot = -1;
// 			}
// 			if (rot == -1)
// 			{
// 				// if (*stack_b && index != -1
// 				// 	&& arr->a[index] > (*stack_b)->number
// 				// 	&& is_inchunk(arr->a, get_last(*stack_b)->number, arr->size))
// 				// 	run(RRR, stack_a, stack_b);
// 				// else
// 					run(RRA, stack_a, stack_b);
// 			}
// 			else if (rot == 1)
// 			{
// 				// if (*stack_b && (*stack_b)->next && index != -1
// 				// 	&& arr->a[index] < (*stack_b)->number
// 				// 	&& is_inchunk(arr->a, (*stack_b)->next->number, arr->size))
// 				// 	run(RR, stack_a, stack_b);
// 				// else
// 					run(RA, stack_a, stack_b);
// 			}
// 		}
// 	}
// }


// int mainw(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack *stack_b;
// 	t_arr	*arr;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	arr = NULL;
// 	fill_stack(&stack_a, argc, argv);
// 	if (is_sorted(stack_a))
// 	{
// 		free_stack(stack_a);
// 		free_stack(stack_b);
// 		return (0);
// 	}
// 	fill_arr(&arr, argc, stack_a);
// 	quick_sort(arr->a, 0, arr->size - 1);
// 	// load_chunks(&stack_a, &stack_b, arr);
// 	load_chunks2(&stack_a, &stack_b, arr);
// 	load_back(&stack_a, &stack_b, arr);
	
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	free_arr(arr);	
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	mainw(argc, argv);
// 	//system("leaks a.out");
// 	return (0);
// }