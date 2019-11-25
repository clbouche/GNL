/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:57:12 by clbouche          #+#    #+#             */
/*   Updated: 2019/11/25 13:34:51 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_form_line(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!(s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[j] && s1[j] != '\n')
	{
		s2[j] = s1[j];
		j++;
		i--;
	}
	s2[j] = '\0';
	return ((char *)s2);
}

int get_next_line(int fd, char **line)
{
	int			op;
	char		*buff; 
	static char	*str;

	op = 0;
	if (fd < 1 || !line || BUFFER_SIZE <= 0) 
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((op = read(fd, buff, BUFFER_SIZE)) > 0) 
	{
		buff[op] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(buff, '\n'))
		{
			break;
		}
	}
	free(buff);
	*line = ft_form_line(str);
	if (op == 0)
		return (0);
	return(1);
}