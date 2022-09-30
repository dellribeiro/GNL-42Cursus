/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:28:24 by whendrix          #+#    #+#             */
/*   Updated: 2022/07/10 03:28:10 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h> 

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *buffer, char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_endl(char *str);
void	*ft_get_line(char *buffer);
void	*ft_new_str(char *buffer);
void	*ft_read_str(int fd, char *buffer);
char	*get_next_line(int fd);

#endif