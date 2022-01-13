/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:21:59 by lcombo            #+#    #+#             */
/*   Updated: 2022/01/10 20:08:28 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_first_str(int fd, char *first_str);
char	*ft_strchr(char	*str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *first_str);
char	*ft_new_str(char *first_str);
size_t	ft_strlen(char *s);

#endif
