/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:25:39 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:07 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str1)
{
	char	*str2;
	int		i;

	i = 0;
	if (!str1)
		return (NULL);
	if (!(str2 = malloc(ft_strlen(str1) + 1)))
		return (NULL);
	while (str1[i])
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}


char	*ft_substr(char *str, int c, int len)
{
	char	*dst;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) < c)
		return (ft_strdup(""));
	if (!(dst = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i + c];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(str1) +
			ft_strlen(str2)) + 1)))
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i])
	{
		str[ft_strlen(str1) + i] = str2[i];
		i++;
	}
	str[ft_strlen(str1) + i] = '\0';
	return (str);
}