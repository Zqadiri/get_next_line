/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:08:41 by zqadiri           #+#    #+#             */
/*   Updated: 2019/11/06 20:12:37 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *src)
{
	int		size;
	char	*p;
	int		i;

	i = 0;
	size = 0;
	while (src[i] != '\0')
	{
		i++;
		size++;
	}
	size++;
	p = (char *)malloc(size * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		*(p + i) = src[i];
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	char		*p;
	int			size_s1;
	int			size_s2;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	p = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (p)
	{
		while (s1[++i] != '\0')
			p[i] = s1[i];
		while (s2[j])
			p[i++] = s2[j++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

int			get_next_line(int fd, char **line)
{
	static char		*save;
	int				r;
	char			*buff;
	char			*ptr;

	if (fd < 0 || !line || (!(buff = malloc(BUFFER_SIZE + 1))))
		return (-1);
	if (!save)
		save = ft_strdup("");
	while (!(ft_strchr(save, '\n')) && ((r = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[r] = '\0';
		ptr = save;
		save = ft_strjoin(save, buff);
		free_ptr(&ptr, &ptr, 1, 0);
	}
	if (ft_strchr(save, '\n') != NULL)
	{
		*line = ft_substr(save, 0, ft_strlength(save));
		ptr = save;
		save = ft_strdup(save + ft_strlength(save) + 1);
		return (free_ptr(&ptr, &buff, 2, 1));
	}
	*line = ft_strdup(save);
	return (free_ptr(&save, &buff, 2, 0));
}
