
#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;
    int     i;

	char *str;

    i = 0;
    fd = open("bite.txt", O_RDONLY);
    while (i < 10)
    {
		str = get_next_line(fd);
        printf("%s", str);
        i++;
    }
    close(fd);
	free(str);
    return (0);
}

char    *get_next_line(int fd)
{
    static char    *str = NULL;

    char    buff[BUFFER_SIZE + 1];
    int     i;
	char *temp;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    i = 1;
    while (i > 0)
    {
        i = read(fd, buff, BUFFER_SIZE);
        if ((i == -1) || (i == 0 && !str))
			return (NULL);

		buff[i] = '\0';
		str = ft_buff_to_string(buff, str);
        if(ft_strchr(str, '\n') || (i == 0 && str[0]))
		{
			temp = ft_parse_string(str);
			str = &str[ft_strnlen(temp) + 1];
			return (temp);
		}
    }
	free(str);
	return (NULL);
}

char	*ft_parse_string(char *str)
{
	char *temp;
	
	temp = ft_strndup(str);
	free(str);
	return(temp);
}

char	*ft_buff_to_string(char *buff, char *str)

{
	char *temp;
	
	if(str)
        {
            temp = ft_strjoin(str, buff);
			str = NULL;
			free(str);
        }
    else 
		temp = ft_strdup(buff);
	return(temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strnlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(*src) * (ft_strnlen(src) + 1));
	if (!dest)
		return (0);
	while (src[i] != '\n' && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
    dest[i + 1] = '\0'; 
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
		j++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);

}
