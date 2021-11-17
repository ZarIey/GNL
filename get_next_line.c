/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:02:58 by ctardy            #+#    #+#             */
/*   Updated: 2021/11/17 12:16:24 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#define BUFFER_SIZE 1

char	*read_buff(char *str, int fd)
{
	char	*buff;
	int		i;
	
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	i = 1;
	while ((int)ft_strchr(str, '\n') == 0 && i > 0)
	{
	//	printf("kikoo");
		//buff[0] = '\0';
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buff);
			if (str && *str)
				return (str);
			return (NULL);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return(str);
}

char *cut_str(char *str)
{
	char	*inter;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	inter = malloc(i + 2);
	if (inter == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		inter[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		inter[i++] = '\n';
	inter[i] = '\0';
	return (inter);
}

char *buff_to_str(char *str)
{
	char *buff;
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	buff = malloc(ft_strlen(str) - i + 1); // LEAK ICI FLECHE
	if (buff == NULL)
		return (NULL);
	i++;
	while (str[i])
		buff[j++] = str[i++];
	buff[j] = '\0';
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*inter;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_buff(str, fd);
	if (str == NULL)
		return (NULL);
	inter = cut_str(str);
	str = buff_to_str(str);
	return (inter);
}
/*
int main()
{
	int fd;
	fd = open("Fichier_a_lire", O_RDONLY);
	printf("1. '%s'\n", get_next_line(fd));
	printf("2. '%s'\n", get_next_line(fd));	
	printf("3. '%s'\n", get_next_line(fd));
	printf("4. '%s'\n", get_next_line(fd));
}
*/