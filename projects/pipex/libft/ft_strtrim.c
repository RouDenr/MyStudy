/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:22:03 by decordel          #+#    #+#             */
/*   Updated: 2021/10/13 19:23:21 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	isset(char c, char const *set)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

static char	*find_end(char const *s, char const *set)
{
	if (!*s)
		return ((char *)s);
	while (*s)
		s++;
	s--;
	while (isset(*s, set))
		s--;
	return ((char *)s);
}

static size_t	count_chars(char const *s, char *end)
{
	size_t	i;

	i = 0;
	while (s++ != end && s[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;
	char	*endstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (isset(*s1, set))
		s1++;
	endstr = find_end(s1, set);
	str = malloc(count_chars(s1, endstr) + 2);
	if (str == NULL)
		return (NULL);
	while (s1 <= endstr)
		str[i++] = *(s1++);
	str[i] = '\0';
	return (str);
}
