/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:52:46 by zqadiri           #+#    #+#             */
/*   Updated: 2019/11/06 18:30:10 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
unsigned int	ft_strlength(char *save);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(char *save, char c);
int				free_ptr(char **ptr, char **buff, int f, int r);
int				ft_helper(char **line, char *save);
#endif
