/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:30:24 by crossart          #+#    #+#             */
/*   Updated: 2021/01/15 10:41:40 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_init(char *str)
{
	if (!(str = malloc(sizeof(char))))
		return (NULL);
	str[0] = 0;
	return (str);
}

int		n_in_str(char *line_rem)
{
	int		i;

	i = 0;
	while (line_rem[i] && line_rem[i] != '\n')
		i++;
	if (line_rem[i] != '\n')
		return (-1);
	return (i);
}

int		one_line(char **line, char *line_rem, int i)
{
	int		l;
	int		j;

	j = 0;
	*line = ft_substr(line_rem, 0, i);
	++i;
	l = ft_strlen(line_rem + i) + 1;
	while (j < l)
	{
		line_rem[j] = (line_rem + i)[j];
		j++;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*line_rem;
	char			buffer[BUFFER_SIZE + 1];
	int				i;
	int				b;

	if (!line || !BUFFER_SIZE || fd < 0 || read(fd, buffer, 0) == -1)
		return (-1);
	if (line_rem && (((i = n_in_str(line_rem)) >= 0)))
		return (one_line(line, line_rem, i));
	if (!line_rem)
		line_rem = str_init(line_rem);
	while ((b = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[b] = '\0';
		line_rem = ft_strjoin(line_rem, buffer);
		if (((i = n_in_str(line_rem)) >= 0))
			return (one_line(line, line_rem, i));
	}
	if (line_rem)
	{
		*line = ft_strjoin(str_init(*line), line_rem);
		free(line_rem);
		line_rem = NULL;
	}
	return (0);
}
