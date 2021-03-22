/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:06:06 by epilar            #+#    #+#             */
/*   Updated: 2020/11/16 15:23:59 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	int				fd;
	char			*accum;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_strnew(size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(char *str);

#endif
