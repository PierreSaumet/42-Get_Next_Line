/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:00:39 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:06:56 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **tab)
{
	if (tab != NULL && *tab != NULL)
	{
		free(*tab);
		*tab = NULL;
	}
	return ;
}

char	*ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)str + i);
		i++;
	}
	if (str[i] == '\n')
		return ((char *)str + i);
	return (0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	int ret;

	ret = 0;
	(void)fd;
	(void)line;
	return (ret);
}