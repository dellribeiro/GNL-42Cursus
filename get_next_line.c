/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:57:23 by whendrix          #+#    #+#             */
/*   Updated: 2022/08/02 20:52:52 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_substr(buffer, 0, i + ft_endl(buffer));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_new_str(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*ft_read_str(int fd, char *buffer)
{
	char	*s;
	int		bytes;

	s = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!s)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, s, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(s);
			return (NULL);
		}
		s[bytes] = '\0';
		buffer = ft_strjoin(buffer, s);
	}
	free(s);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_str(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_new_str(buffer);
	return (line);
}

/*int    main(void)
{
    char    *line;
    int        i;
    int        fd;
    fd = open("file1.txt", O_RDONLY);
    i = 1;
    while (i < 7)
    {
        line = get_next_line(fd);
        printf("line [%02d]: %s", i, line);
        free(line);
        i++;
    }
	if (i == -1)
	{
		printf("<ERROR>\n");
		close(fd);
		return (-1);
	}
    close(fd);
    return (0);
}*/
