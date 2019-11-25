/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:39:46 by clbouche          #+#    #+#             */
/*   Updated: 2019/11/25 10:35:03 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char *s;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (s == d)
		return (dst);
	if (s > d)
		while (len)
		{
			*d = *s;
			d++;
			s++;
			len--;
		}
	else if (s < d)
		while (len--)
		{
			*(d + len) = *(s + len);
		}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_memmove(new, s1, len1);
	ft_memmove(&new[len1], s2, len2);
	new[len1 + len2] = '\0';
	free((void *)s1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (s == '\0' || c == 0)
		return ((char *)s);
	else
		return (0);
}

