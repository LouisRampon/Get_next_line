
#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;
    int     i;

	char *str;

    i = 0;
    fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
		free(str);
		str = get_next_line(fd);
    }
    close(fd);
	free(str);
    return (0);
}

char    *get_next_line(int fd)
{
    static char    *str = NULL;
	char	*temp;
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
		buff[i] = '\0';
		str = ft_buff_to_string(buff, str);
        if(ft_strchr(str, '\n'))
		{
			temp = ft_strndup(str);
			str = &str[ft_strnlen(str) + 1];
			//printf("str = %s //fin", str);
			return (temp);
		}
	}
	if (str && !str[0])
		temp = NULL;
	else
		temp = ft_strdup(str);
	free(str);
	str = NULL;
	return (temp);
}

char	*ft_buff_to_string(char *buff, char *str)
{
	char *temp;
	
	if(str)
        {
			temp = str;
            str = ft_strjoin(temp, buff);	
        }
    else
		str = ft_strdup(buff);
	return(str);
}

char	*ft_strjoin(char *s1, char *s2)
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