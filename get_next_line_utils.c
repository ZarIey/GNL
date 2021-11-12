/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:02:47 by ctardy            #+#    #+#             */
/*   Updated: 2021/11/12 19:52:11 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*inter;
	size_t	join_size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	join_size = ft_strlen(s1) + ft_strlen(s2);
	inter = malloc(sizeof(char) * join_size + 1);
	if (inter == NULL)
		return (NULL);
	while (s1[i])
	{
		inter[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		inter[i++] = s2[j++];
	inter[i] = '\0';
	free(s1);
	return (inter);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s)
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				return (s + i);
			i++;
		}
	}
	return (0);
}
