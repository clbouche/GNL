/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:59:52 by clbouche          #+#    #+#             */
/*   Updated: 2019/11/22 16:57:11 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif