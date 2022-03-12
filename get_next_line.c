#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;
    int     i;

    i = 0;
    fd = open("bite.txt", O_RDONLY);
    while (i < 5)
    {
        printf("%s",(get_next_line(fd)));
        i++;
    }
    close(fd);

    return (0);
}

char    *get_next_line(int fd)
{
    static char    *str = NULL;
    static int      line = 0;
    char     *temp;
    char    buff[BUFFER_SIZE + 1];
    int     i;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    i = 1;
    while (i > 0)
    {
        i = read(fd, buff, BUFFER_SIZE);
        if ((i == -1) || (i == 0 && !str))
			return (NULL);
        if(str)
        {
            temp = str;
            str = ft_strjoin(temp, buff);
            free(temp);
        }
        else
            str = ft_strdup(buff);
        while (line > 0)
        {
            str = &str[ft_strnlen(str) + 1];
            line--;
        }
        if(ft_strchr(str, '\n'))
        {
            temp = ft_strndup(str);
            line++;
            return(temp);
        }
    }
    return(NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
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
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}



