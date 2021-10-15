#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
void	*ft_realloc(void *ptr, int newsize);
char	*ft_clear(int bug, char **line, char **remain);
char	*ft_reading(int fd, char **line, char **remain);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
