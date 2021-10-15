#include "get_next_line.h"

void	*ft_realloc(void *ptr, int newsize)
{
	void	*new;
	int		i;

	new = malloc(newsize);
	if (!new)
		return (NULL);
	i = 0;
	while (ptr && i < newsize && ((char *)ptr)[i])
	{
		((char *)new)[i] = ((char *)ptr)[i];
		i++;
	}
	((char *)new)[i] = '\0';
	if (ptr)
		free(ptr);
	return (new);
}

char	*ft_clear(int bug, char **line, char **remain)
{
	if ((*line && bug < 0) || (*line && **line == 0 && bug == 0))
	{
		free(*line);
		*line = NULL;
	}
	if (*remain && bug == -1)
	{
		free(*remain);
		*remain = NULL;
	}
	return (*line);
}

char	*ft_reading(int fd, char **line, char **remain)
{
	char		buf[BUFFER_SIZE + 1];
	char		*end;
	size_t		len;
	int			bug;

	len = ft_strlen(*line) + 1;
	while (1)
	{
		bug = read(fd, buf, BUFFER_SIZE);
		buf[bug] = 0;
		if (bug <= 0)
			 return (ft_clear(bug, line, remain));
		end = ft_strchr(buf, '\n');
		if (end)
			break ;
		len += bug;
		*line = ft_realloc(*line, len);
		ft_strlcat(*line, buf, len);
	}
	len += end - buf + 1;
	*line = ft_realloc(*line, len);
	ft_strlcat(*line, buf, len);
	*remain = ft_substr(buf, end - buf + 1, BUFFER_SIZE);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*end;
	char		*start;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remain)
	{
		end = ft_strchr(remain, '\n');
		if (end)
		{
			line = ft_substr(remain, 0, end - remain + 1);
			start = ft_substr(remain, end - remain + 1, BUFFER_SIZE);
			free(remain);
			remain = start;
			return (line);
		}
		line = remain;
		remain = NULL;
	}
	else
		line = ft_realloc(line, 1);
	return (ft_reading(fd, &line, &remain));
}
