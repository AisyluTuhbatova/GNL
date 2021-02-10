/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:44:33 by crossart          #+#    #+#             */
/*   Updated: 2021/01/11 14:49:58 by crossart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ch;
	int		i;
	int		j;
	int		k;

	if (!s1 && !s2)
		return (NULL);
	k = 0;
	j = ft_strlen(s2);
	i = ft_strlen(s1);
	if (!(ch = (char *)malloc((i + j + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s2[j] || s1[i])
	{
		while (s1[i])
			ch[k++] = s1[i++];
		ch[k++] = s2[j++];
	}
	ch[k] = '\0';
	free((char *)s1);
	s1 = NULL;
	return (ch);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*ch;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	if (!(ch = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (start < j && s[start] && i < len)
		ch[i++] = s[start++];
	ch[i] = '\0';
	return (ch);
}
