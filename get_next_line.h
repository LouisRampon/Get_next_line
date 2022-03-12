#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src);
size_t	ft_strnlen(const char *str);
char	*ft_buff_to_string(char *buff, char *str);
char	*ft_parse_string(char *str);

#endif