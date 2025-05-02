/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfurnea <rfurnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:40:47 by rfurnea           #+#    #+#             */
/*   Updated: 2025/04/27 19:02:08 by rfurnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define ERR_OK          200
#define ERR_ALLOC       -42

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t  gnl_strlen(const char *s);
char    *gnl_strchr(const char *s, int c);
char    *gnl_strjoin(const char *s1, const char *s2);
char    *gnl_substr(const char *s, unsigned int start, size_t len);
void    gnl_memcpy(char *dst, const char *src, size_t n);

#endif