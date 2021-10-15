#include "get_next_line.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;

	if (!str)
		return (NULL);
	if (!len || start >= ft_strlen(str))
	{
		sub = malloc(1);
		*sub = 0;
		return (sub);
	}
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &str[start], len + 1);
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	const char	ch = c;

	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;

	if (!dst && !size)
		return (ft_strlen(src));
	size_dst = ft_strlen(dst);
	i = size_dst;
	if (size_dst >= size)
		return (ft_strlen(src) + size);
	while (i < size - 1 && src[i - size_dst])
	{
		dst[i] = src[i - size_dst];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + size_dst);
}
