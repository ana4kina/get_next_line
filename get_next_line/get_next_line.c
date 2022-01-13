/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:22:08 by lcombo            #+#    #+#             */
/*   Updated: 2022/01/10 19:59:34 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_first_str(int fd, char *first_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(first_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		first_str = ft_strjoin(first_str, buff);
	}
	free(buff);
	return (first_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*first_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	first_str = ft_read_to_first_str(fd, first_str);
	if (!first_str)
		return (NULL);
	line = ft_get_line(first_str);
	first_str = ft_new_str(first_str);
	return (line);
}
