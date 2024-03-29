/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2024/01/04 07:39:39 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	int			nb_read;
	int			len_line;
	char		*line;
	static char	*buffer;

	nb_read = 1;
	line = "";
	while ((*line == '\0' && buffer && *buffer) || (nb_read > 0 && fd >= 0))
	{
		len_line = has_line(buffer, nb_read);
		if (len_line)
		{
			line = extract_line(buffer, nb_read);
			buffer = remove_extracted_line(buffer, len_line);
			return (line);
		}
		else
			buffer = extract_from_file(fd, buffer, &nb_read);
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (NULL);
}
