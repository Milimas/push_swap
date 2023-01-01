/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:34:42 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/12/16 03:36:05 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../include/push_swap.h"

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		exit_on_error(1, "Invalid input, Input is not a number");
	while (*str)
	{
		if (!ft_isdigit(*str))
			exit_on_error(1, "Invalid input, Input is not a number");
		num = num * 10 + (*str++ - '0');
		if (num > INT_MAX && sign == 1)
			exit_on_error(1, "Invalid input, Number is bigger than MAX_INT");
		if (sign * num < INT_MIN && sign == -1)
			exit_on_error(1, "Invalid input, Number is smaller than MIN_INT");
	}
	return ((int)(sign * num));
}
