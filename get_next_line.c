/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:57:12 by clbouche          #+#    #+#             */
/*   Updated: 2019/11/27 15:53:30 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_savetxt(char *s)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!(save = malloc(sizeof(char) * (ft_strlen(s)) - i + 1)))
		return (0);
	j = 0;
	i++;
	while (s[i])
	{
		save[j] = s[i];
		i++;
		j++;
	}
	free(s);
	save[j] = '\0';
	return (save);
}

int		get_next_line(int fd, char **line)
{
	int			op;
	char		*buff;
	static char	*str;

	op = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (op != 0 && ft_check(str) != -1)
	{
		if ((op = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[op] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	*line = ft_form_line(str);
	str = ft_savetxt(str);
	if (op == 0)
		return (0);
	return (1);
}
