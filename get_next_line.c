/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2023/12/05 08:30:30 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "get_next_line.h"
# include <stdio.h>

char	*get_next_line(int fd)
{
	char	*str;
	static int	i;
	int	buffer_size;

	buffer_size = 10;
	if (!i)
		i = 0;
	str = (char *)malloc(10 * sizeof(char));
	read(fd, str, buffer_size);
	i++;
	printf("%d° leitura: %s\n", i, str);
	return (str);
}

int main()
{
	int	fd;
	int	buffer_size;
	char	*str;	
	
	str = (char *)malloc(10 * sizeof(char));
	buffer_size = 10;
	fd = open("teste.txt", O_RDONLY);
	printf("O fd do meu arquivo %d\n", fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
}

