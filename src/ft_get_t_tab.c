/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:19:41 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/28 11:19:43 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		**add_path(char **order, char *dirname)
{
	int i;

	i = 0;
	while (order[i])
	{
		order[i] = ft_strjoin("/", order[i]);
		order[i] = ft_strjoin(dirname, order[i]);
		i++;
	}
	return (order);
}

static time_t	get_time(char *this)
{
	struct stat		fstat;;

	if (lstat(this, &fstat) == -1)
	{
		perror("");
		exit(0);
	}
	return (*(&fstat.st_mtime));
}

char			**ft_get_t_tab(char *dirname, char **order, int r_opt)
{
	int		i;
	char 	*buffer;

	i = 0;
	order = add_path(order, dirname);
	while (order[i])
	{
		if (r_opt == 0)
		{
			if (order[i + 1] && get_time(order[i]) < get_time(order[i + 1]))
			{
				buffer = ft_strdup(order[i]);
				order[i] = ft_strdup(order[i + 1]);
				order[i + 1] = ft_strdup(buffer);
				free(buffer);
				i = 0;
			}
		}
		else
		{
			if (order[i + 1] && get_time(order[i]) > get_time(order[i + 1]))
			{
				buffer = ft_strdup(order[i]);
				order[i] = ft_strdup(order[i + 1]);
				order[i + 1] = ft_strdup(buffer);
				free(buffer);
				i = 0;
			}
		}
		i++;
	}
	return (order);
}
