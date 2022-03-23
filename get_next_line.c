
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