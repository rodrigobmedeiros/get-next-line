/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:31:27 by robernar          #+#    #+#             */
/*   Updated: 2023/12/07 01:12:52 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "get_next_line.h"
# include <stdio.h>

char	*get_next_line(int fd)
{
	int		first_call;
	int		n_bytes_read;
	static char	*str;

	if (!first_call)
	{
		// Aqui caso seja uma primeira chamada faco a primeira definicao 
		str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		read(fd, str, BUFFER_SIZE);
	}
	// Verifico se na string existe uma linha fechada. Caso exista, eu extraio e retorno ela.
	// Recalculo a str considerado a linha que removi.
	// Caso nao exista, faco um read novamente atualizando o malloc com + BUFFER_SIZE e procurando a linha de novo.
	// Faco esse processo ate que nao tenha mais linhas no meu buffer e quando ler o arquivo este esteja vazio
	// Dai retorno null.
	// Lembrar de pensar em uma boa logica para desalocar memoria. 
	n_bytes_read = read(fd, str, buffer_size);
	if (!n_bytes_read || n_bytes_read == -1)
	{
		free(str);
		printf("Nao ha mais nada para ser lido no arquivo");
		return (NULL);
	}
	i++;
	printf("%d° leitura: %s\n", i, str);
	return (str);
}

int main()
{
	int	fd;
	char	*str;

	fd = open("teste.txt", O_RDONLY);
	printf("O fd do meu arquivo %d\n", fd);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
	printf("%s\n", str);
	str = get_next_line(fd);
        printf("%s\n", str);
	close(fd);
	printf("%s\n", str);
	printf("Buffer size = %d\n", BUFFER_SIZE);
}

