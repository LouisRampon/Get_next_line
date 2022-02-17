
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buff_read = 0;
	char			*buffer;
	char			*line;
	ssize_t			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (0);
	}
	if (!buff_read)
		buff_read = ft_strdup("");
	n = read_file(fd, &buffer, &buff_read, &line);
	if (n == 0 && !line)
		return (0);
	return (line);
}

ssize_t	read_file(int fd, char **buffer, char **buff_read, char **line)
{
	char	*temp;
	ssize_t	n;

	n = 1;
	while (!ft_strchr(*buff_read, '\n') && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		temp = *buff_read;
		*buff_read = ft_strjoin(temp, *buffer);
		free(temp);
	}
	free(*buffer);
	*buffer = 0;
	*buff_read = get_line(buff_read, line);
	if (**line == '\0')
	{
		free(*line);
		*line = 0;
	}
	return (n);
}

char	*get_line(char **buff_read, char **line)
{
	size_t	i;
	char	*new_buff;

	i = 0;
	new_buff = 0;
	while ((*(*buff_read + i) != '\n') && (*(*buff_read + i) != '\0'))
		i++;
	if (*(*buff_read + i) == '\n')
	{
		i++;
		*line = ft_substr(*buff_read, 0, i);
		new_buff = ft_strdup(*buff_read + i);
	}
	else
		*line = ft_strdup(*buff_read);
	free(*buff_read);
	*buff_read = 0;
	return (new_buff);
}

int	main(void)
{
	char *line;
	int	fd;
	int	i;

	fd = open("bite.txt", O_RDONLY);
	i = 1;
	while (i < 40)
	{
		line = get_next_line(fd);
		printf("line [%d]: %s", i, line);
		free (line);
		i++;
	}
	close(fd);
	return (0);
}



