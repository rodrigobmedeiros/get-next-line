/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2023/12/28 06:38:37 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			n_bytes_read;
	static char	*buffer;
	char		*line;
	int			len_line;

	line = "";
	n_bytes_read = 1;
	while ((!line && *buffer) || n_bytes_read > 0)
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
			n_bytes_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE);
		}
	}
	free(buffer);
	return (NULL);
}
/*
int main()
{
	int	fd;
	char	*str;
	
	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (str)
			printf("%s", str);
	}
	close(fd);
}
*/
