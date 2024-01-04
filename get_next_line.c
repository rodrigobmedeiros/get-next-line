/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2024/01/03 05:22:37 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

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

static char	*resize_buffer(char *buffer)
{
	char	*resized_buffer;
	int		len_buffer;
	int		n;
	int		resized_len;

	len_buffer = ft_strlen(buffer);
	resized_len = len_buffer + BUFFER_SIZE + 1;
	resized_buffer = (char *)malloc(sizeof(char) * resized_len);
	n = 0;
	while (n < len_buffer)
	{
		resized_buffer[n] = buffer[n];
		n++;
	}
	while (n < len_buffer + BUFFER_SIZE + 1)
	{
		resized_buffer[n] = '\0';
		n++;
	}
	free(buffer);
	return (resized_buffer);
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
		return extract_line_with_no_break(str);
	return (extract_line_with_break(str));
}

char	*get_next_line(int fd)
{
	int		nb_read;
	static char	*buffer;
	char		*line;
	int		len_line;

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
		{
			buffer = resize_buffer(buffer);
			nb_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE);
		}
	}
	if (*buffer)
		free(buffer);
	return (NULL);
}

/*int main()
{
	int	fd;
	char	*str;

	fd = open("41_no_nl", O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		printf("(null)\n");
	else
	{
		printf("%s\n", str);
		free(str);
	}
	close(fd);
}*/