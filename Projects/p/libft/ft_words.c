/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:10:51 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/12 16:06:19 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	if (!str || c == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_nextword(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s || c == '\0')
		return (NULL);
	while (s[i] && s[i] != c)
	{
		i++;
	}
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (NULL);
	return ((char *)s + i);
}
