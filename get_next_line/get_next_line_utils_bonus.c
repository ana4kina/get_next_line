/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:21:40 by lcombo            #+#    #+#             */
/*   Updated: 2022/01/09 23:27:57 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strchr(char	*str, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (!str)
		return (NULL);
	if (ch == '\0')
	{
		while (*str)
			++str;
		return ((char *) str);
	}
	while (*str)
	{
		if (*str == ch)
			return ((char *) str);
		++str;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned char	*str;
	size_t			i;
	size_t			j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	j = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return ((char *)str);
}

char	*ft_get_line(char *first_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!first_str[i])
		return (NULL);
	while (first_str[i] && first_str[i] != '\n')
		++i;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (first_str[i] && first_str[i] != '\n')
	{
		str[i] = first_str[i];
		++i;
	}
	if (first_str[i] == '\n')
	{
		str[i] = first_str[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_str(char *first_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (first_str[i] && first_str[i] != '\n')
		i++;
	if (!first_str[i])
	{
		free(first_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(first_str) - i + 1));
	if (!str)
		return (NULL);
	++i;
	j = 0;
	while (first_str[i])
		str[j++] = first_str[i++];
	str[j] = '\0';
	free(first_str);
	return (str);
}
