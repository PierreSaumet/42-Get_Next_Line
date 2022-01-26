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

int		get_next_line(int fd, char **line)
{
	int ret;

	ret = 0;
	(void)fd;
	(void)line;
	return (ret);
}