/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:38:04 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/12 16:14:21 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, int c)
{
	int	count;

	count = 0;
	if (s)
	{
		while (*s)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				while (*s && *s++ != c)
					;
				count++;
			}
		}
	}
	return (count);
}

static void	*deleteall(char ***res, int i)
{
	while (i > 0)
		free(*res[i--]);
	free(*res);
	return (NULL);
}

static char	*ft_start(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len_w;
	int		i;
	char	*st_wrd;
	char	**res;

	if (!(res = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s && *s)
	{
		len_w = 0;
		s = ft_start((char *)s, c);
		if (*s)
		{
			st_wrd = (char *)s;
			while (*s && *s++ != c)
				len_w++;
			if (!(res[i] = (char *)malloc(sizeof(char) * (len_w + 1))))
				return (deleteall(&res, i));
			ft_strncpy(res[i], st_wrd, len_w);
			res[i++][len_w] = 0;
		}
	}
	res[i] = 0;
	return (res);
}
