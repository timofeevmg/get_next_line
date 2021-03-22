/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:03:59 by epilar            #+#    #+#             */
/*   Updated: 2020/11/15 16:02:04 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_line(char *str)
{
	int		i;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = '\0';
	i--;
	while (i >= 0)
	{
		ret[i] = str[i];
		i--;
	}
	return (ret);
}

char	*cut_accum(char *accum)
{
	char	*new;
	int		i;
	int		j;

	if (!accum)
		return (NULL);
	i = 0;
	while (accum[i] && accum[i] != '\n')
		i++;
	if (!accum[i])
	{
		free(accum);
		return (NULL);
	}
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(accum) - i + 1))))
		return (NULL);
	i++;
	j = 0;
	while (accum[i])
		new[j++] = accum[i++];
	new[j] = '\0';
	free(accum);
	return (new);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			rd;
	static char	*accum;

	rd = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!accum)
		accum = ft_strnew(1);
	while (!ft_strchr(accum, '\n') && rd != 0)
	{
		if ((rd = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[rd] = '\0';
		accum = ft_strjoin(accum, buf);
	}
	free(buf);
	*line = find_line(accum);
	accum = cut_accum(accum);
	return (rd == 0 ? 0 : 1);
}
