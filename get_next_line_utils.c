/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:33:15 by robernar          #+#    #+#             */
/*   Updated: 2024/01/04 06:39:33 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

char	*extract_line_with_break(char *str)
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

char	*extract_line_with_no_break(char *str)
{
	char	*line;
	int		len_str;
	int		i;

	len_str = ft_strlen(str);
	line = (char *)malloc(sizeof(char) * (len_str + 1));
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
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
	if (buffer)
		free(buffer);
	return (resized_buffer);
}
