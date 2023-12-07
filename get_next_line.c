/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2023/12/07 09:31:47 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "get_next_line.h"
# include <stdio.h>

int	has_breakline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*extract_line(char *str)
{
	char	*line;
	int		counter;

	counter = 0;
	while (str[counter] != '\n')
		counter++;
	line = (char *)malloc(sizeof(char) * (counter + 2)); // adiciono dois por conta do \n e \0
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

char	*get_next_line(int fd)
{
	static int	not_first_call;
	int			n_bytes_read;
	static char	*str;
	char		*line;

	n_bytes_read = 0; // Soh para ajudar a implementar a ideia q estou pensando.
	if (!not_first_call)
	{
		not_first_call = 1; // defino aqui que nao eh mais a primeira chamada.
		// Aqui caso seja uma primeira chamada faco a primeira definicao 
		str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		str[BUFFER_SIZE] = '\0';
		n_bytes_read = read(fd, str, BUFFER_SIZE);
		if (!n_bytes_read || n_bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
	}
	// Nesse ponto a principio eu tenho uma str com coisa dentro.
	if (has_breakline(str)) // esse cara aqui verifica se tem linha dentro.
	{
		line = extract_line(str);
		printf("encontrou o breakline\n");
	}
	//extract_line() // vai extrair a linha uma vez que tem quebra
	// Se nao tiver quebra de linha, tenho que dar o read novamente primeiro redimensionando o buffer e depois passando o ponteiro a partir daquele ponto.
	// Verifico se na string existe uma linha fechada. Caso exista, eu extraio e retorno ela.
	// Recalculo a str considerado a linha que removi.
	// Caso nao exista, faco um read novamente atualizando o malloc com + BUFFER_SIZE e procurando a linha de novo.
	// Faco esse processo ate que nao tenha mais linhas no meu buffer e quando ler o arquivo este esteja vazio
	// Dai retorno null.
	// Lembrar de pensar em uma boa logica para desalocar memoria.
	free(str);	
	return (line);
}

int main()
{
	int	fd;
	char	*str;
	
	fd = open("teste.txt", O_RDONLY);
	printf("O fd do meu arquivo %d\n", fd);
	str = get_next_line(fd);
	printf("%s\n", str);
	close(fd);
}
