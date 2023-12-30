/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2023/12/30 17:17:20 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

static int	validate_fd(int fd)
{
	char	buffer[1];
	int	b_read;

	if (fd < 0)
		return (0);
	b_read = read(fd, buffer, 1);
	if (b_read <= 0)
		return (0);
	return (1);
}

static char	*get_next_line_logic(int fd)
{
	int		nb_read;
	static char	*buffer;
	char		*line;
	int		len_line;

	nb_read = 1;
	line = "";
	while ((!line && *buffer) || nb_read > 0)
	{
		len_line = has_breakline(buffer);
		if (len_line)
		{
			line = extract_line(buffer);
			buffer = remove_extracted_line(buffer, len_line);
			return (line);
		}
		else
		{
			buffer = resize_buffer(buffer);
			nb_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE);
		}
	}
	free(buffer);
	return (NULL);
}

/**
 * Here the get_next_line is a wrapper that validate the fd checking if it's valid and
 * not empty. If this validation is OK, the get_next_line_logic is called, extracting the
 * line.
 * 
 * @param fd file descriptor to read.
 * @return the next valid line of a file or NULL.
 */
char	*get_next_line(int fd)
{
	if (validate_fd(fd))
		return get_next_line_logic(fd);
	return (NULL);
}

/*
int main()
{
	int	fd;
	char	str[1];
	int	n_bytes;

	fd = open("empty", O_RDONLY);
	n_bytes = read(fd, str, 1);
	printf("%d\n", n_bytes);
	n_bytes = read(fd, str, 1);
        printf("%d\n", n_bytes);
	n_bytes = read(fd, str, 1);
        printf("%d\n", n_bytes);
}*/
