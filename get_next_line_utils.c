/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfurnea <rfurnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:02:44 by rfurnea           #+#    #+#             */
/*   Updated: 2025/04/27 20:04:11 by rfurnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	gnl_memcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	gnl_memcpy(res, s1, len1);
	gnl_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	s_len = gnl_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	gnl_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}
