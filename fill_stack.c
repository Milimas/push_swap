/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:12:20 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/11/27 10:12:41 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_wspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		word_count(char *str)
{
	int	wc;

	wc = 0;
	while (*str)
	{
		while (is_wspace(*str))
			str++;
		if (*str)
			wc++;
		while (*str && !is_wspace(*str))
			str++;
	}
	return (wc);
}

int		word_len(char *str)
{
	char *s;

	s = str;
	while (*str && !is_wspace(*str))
		str++;
	return (str - s);
}

char	*sub_word(char *str)
{
	char	*sub;
	char	*s;
	int		len;

	if (!str)
		return (NULL);
	len = word_len(str);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	s = sub;
	while (*str && is_wspace(*str))
		*s++ = *str++;
	sub[len] = 0;
	return (sub);
}

char	**ft_split(char *str)
{
	char	**split;
	char	**s;

	split = malloc(sizeof(char *) * (word_count(str) + 1));
	if (!split)
		return (NULL);
	s = split;
	while (*str)
	{
		while (*str && is_wspace(*str))
			str++;
		if (*str && !is_wspace(*str))
			*s++ = sub_word(str);
		while (*str && !is_wspace(*str))
			str++;
	}
	*s = 0;
	return (split);
}

// int main (int argc, char **argv)
// {
// 	char **str;

// 	if (argc >= 2)
// 	{
// 		str = ft_split(argv[1]);
// 		while (*str)
// 		{
// 			printf("%s\n", *str++);
// 		}
// 	}
// 	return (0);
// }

void	fill_stack(t_stack **stack, int argc, char **argv)
{
	int	count;
	char **args;

	count = argc - 1;
	if (count == 1)
	{
		args = ft_split(argv[1]);
	}
	else
		while(count--)
		{
			add_back(stack, create_new(atoi(argv[argc - 1 - count])));
		}
	
}

