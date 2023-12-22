/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:33:15 by robernar          #+#    #+#             */
/*   Updated: 2023/12/22 06:29:20 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	has_breakline(char *str)
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
	return (0);
}

int	ft_strlen(char *str)
{
	int	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*extract_line(char *str)
{
	char	*line;
	int		counter;

	counter = 0;
	while (str[counter] != '\n')
		counter++;
	line = (char *)malloc(sizeof(char) * (counter + 2));
	counter = 0;
	while (str[counter] != '\n')
	{
		line[counter] = str[counter];
		counter++;
	}
	line[counter++] = '\n';
	line[counter] = '\0';
	return (line);
}

char	*remove_extracted_line(char *buffer, int len)
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

char	*resize_buffer(char *buffer)
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
