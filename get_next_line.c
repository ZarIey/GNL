/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:02:58 by ctardy            #+#    #+#             */
/*   Updated: 2021/11/12 19:56:35 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1

char	*save_buff(char *str, int fd)
{
	char	*buff;
	int		i;
	
//	printf("%s\n", str);
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	i = 1;
//		printf("Ici peut etre ?\n");
	while (ft_strchr(str, '\n') == 0 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
//		printf("Valeur de i : %d\n", i);
		if (i != 1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
//		printf("%s\n", str);
	}
	free(buff);
	return(str);
}

char *save_line(char *str)
{
//	printf("Je suis dans save line\n");
	char	*inter;
	int		i;
	int		j;

	j = 0;
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

char *suppr_line(char *str)
{
//	printf("Je suis dans suppr line\n");
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
	buff = malloc(ft_strlen(str) - i + 1);
	if (buff == NULL)
		return (NULL);
	i++;
	while (str[i])
	{
		buff[j] = str[i];
		j++;
		i++;
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
//	printf("Je suis dans GNL\n");
	static char	*str;
	char		*inter;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = save_buff(str, fd);
	if (str == NULL)
		return (NULL);
	inter = save_line(str);
	str = suppr_line(str);
	return (inter);
}

int main()
{
	int fd;
	fd = open("Fichier_a_lire", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
