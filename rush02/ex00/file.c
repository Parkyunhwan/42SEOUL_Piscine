/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:36:11 by hakkim            #+#    #+#             */
/*   Updated: 2020/12/06 20:20:00 by hakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		read_line(int fd, char *buf)
{
	int		bp;

	bp = 0;
	while (read(fd, &buf[bp], 1))
	{
		if (buf[bp] == '\n')
			break ;
		bp++;
		if (bp == MAX_NUM - 1)
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
	}
	buf[bp] = 0;
	return (1);
}

int		line_size(int fd)
{
	char	buf;

	g_size = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			g_size++;
	}
	g_list = (t_list *)malloc(sizeof(t_list) * g_size);
	if (g_list == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int		read_file(const char *file)
{
	int		fd;
	int		i;
	char	line[MAX_NUM];

	fd = open_file(file);
	if (fd == -1)
		return (0);
	if (!line_size(fd))
		return (0);
	close(fd);
	fd = open_file(file);
	i = 0;
	while (i < g_size)
	{
		if (!read_line(fd, line))
			return (0);
		if (line[0] != 0)
			if (!ft_split(line, i))
				return (0);
		i++;
	}
	return (1);
}

int		open_file(const char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
	}
	return (fd);
}
