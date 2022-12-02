/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:01:39 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/21 02:13:20 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *stack, char *name)
{
	if (!stack)
		return ;
	int tmp;
	tmp = *stack;
	*stack = *(stack + 1);
	*(stack + 1) = tmp;
	write(1, "s", 1);
	write(1, name, 1);
}
