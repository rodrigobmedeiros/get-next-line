/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:33:38 by robernar          #+#    #+#             */
/*   Updated: 2023/12/22 06:46:51 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		has_breakline(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*extract_line(char *str);
char	*remove_extracted_line(char *buffer, int len);
char	*resize_buffer(char *buffer);

#endif
