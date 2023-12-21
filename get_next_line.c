/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2023/12/21 11:46:57 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "get_next_line.h"

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
		return(0);
	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*extract_line(char *str)
{
	char	*line;
	int	counter;

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

	resized_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer + len) + 1));
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

	len_buffer = ft_strlen(buffer);
	resized_buffer = (char *)malloc(sizeof(char) * (len_buffer + BUFFER_SIZE + 1));
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

char	*get_next_line(int fd)
{
	int		n_bytes_read;
	static char	*buffer;
	char		*line;
	int		len_line;

	n_bytes_read = 1;
	while ((!line && *buffer) || n_bytes_read)
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
			printf("%s\n", str);
	}
	close(fd);
}
