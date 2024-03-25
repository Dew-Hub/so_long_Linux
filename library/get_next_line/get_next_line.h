/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:11:14 by buonturk          #+#    #+#             */
/*   Updated: 2024/01/03 17:22:47 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_free(char **tmp_ram, int next_line);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strdup(const char *str);
#endif
