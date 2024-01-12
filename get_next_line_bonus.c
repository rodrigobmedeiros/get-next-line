/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2024/01/04 07:39:39 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static int	has_line(char *str, int nb_read)
{
	int	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
	{
		if (str[n] == '\n')
			return (n + 1);
		n++;
	}
	if (nb_read == 0)
		return (ft_strlen(str));
	return (0);
}

static char	*remove_extracted_line(char *buffer, int len)
{
	char	*resized_buffer;
	int		n;
	int		resized_len;

	resized_len = ft_strlen(buffer + len) + 1;
	resized_buffer = (char *)malloc(sizeof(char) * resized_len);
	n = 0;
	while (buffer[len + n])
	{
		resized_buffer[n] = buffer[len + n];
		n++;
	}
	resized_buffer[n] = '\0';
	free(buffer);
	return (resized_buffer);
}

static char	*extract_line(char *str, int nb_read)
{
	if (nb_read == 0)
		return (extract_line_with_no_break(str));
	return (extract_line_with_break(str));
}

static char	*extract_from_file(int fd, char *buffer, int *nb_read)
{
	buffer = resize_buffer(buffer);
	*nb_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE);
	return (buffer);
}

/**
 * This is the entry point for reading a file line by line. The main 
 * logic involves reading data from the file in chunks (BUFFER_SIZE) 
 * and searching for a newline character ('\n'). If a newline character 
 * is found, the data up to that point is returned as a line. If a
 * newline character is not found, another portion of data is read 
 * from the file. This process is repeated until the entire file has 
 * been read.
 */
char	*get_next_line(int fd)
{
	int			nb_read;
	int			len_line;
	char		*line;
	static char	*buffer[FD_MAX];

	nb_read = 1;
	line = "";
	if (fd < 0 || fd > FD_MAX)
		return (NULL);
	while ((!*line && buffer[fd] && *buffer[fd]) || (nb_read > 0))
	{
		len_line = has_line(buffer[fd], nb_read);
		if (len_line)
		{
			line = extract_line(buffer[fd], nb_read);
			buffer[fd] = remove_extracted_line(buffer[fd], len_line);
			return (line);
		}
		else
			buffer[fd] = extract_from_file(fd, buffer[fd], &nb_read);
	}
	if (buffer[fd])
		free(buffer[fd]);
	buffer[fd] = NULL;
	return (NULL);
}
