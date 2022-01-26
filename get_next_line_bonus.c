/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:00:39 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/23 11:40:00 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int		ft_gnl(char **str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		if ((*str)[0] == '\0')
			ft_free(str);
		*line = ft_substr(*str, 0, len);
		tmp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = tmp;
	}
	else
	{
		*line = ft_strdup(*str);
		ft_free(str);
		str = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (ft_check_ret(line, ret) == 0)
			return (0);
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd]))
			break ;
	}
	return (ft_final_check(str, line, ret, fd));
}
