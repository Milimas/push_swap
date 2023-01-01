/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:50:39 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/10/26 01:28:40 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*gl_strjoin(char *line, const char *buff);
char	*gl_strchr(char *buff, char c);
char	*get_buff(int fd);
void	*gl_memcpy(void *dst, const void *src, size_t n);
char	*gl_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

#endif
