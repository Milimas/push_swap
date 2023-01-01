/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:56:09 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/13 16:58:28 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*create_new(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->num = number;
	new->next = NULL;
	return (new);
}
