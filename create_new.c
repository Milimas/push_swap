/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:56:09 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/27 09:56:34 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*create_new(int number)
{
	t_stack *new = malloc(sizeof(t_stack));
	new->number = number;
	new->next = NULL;
	return (new);
}
