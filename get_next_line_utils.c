/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:02:53 by zqadiri           #+#    #+#             */
/*   Updated: 2019/11/06 20:16:44 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*p;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		p = (char*)malloc(1 * sizeof(char));
	p = (char *)malloc(len + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	*(p + i) = '\0';
	return (p);
}

char			*ft_strchr(char *save, char c)
{
	size_t	i;

	i = 0;
	while (save[i] != c)
	{
		if (save[i] == '\0')
			return (NULL);
		i++;
	}
	return (save);
}

unsigned int	ft_strlength(char *save)
{
	unsigned int i;

	i = 0;
	while (save[i] != '\n')
		i++;
	return (i);
}

int				free_ptr(char **ptr, char **buff, int f, int r)
{
	free(*ptr);
	*ptr = 0;
	if (f == 2)
	{
		free(*buff);
		*buff = 0;
	}
	return (r);
}
