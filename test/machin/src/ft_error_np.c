/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_np.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:07:45 by cgaspart          #+#    #+#             */
/*   Updated: 2018/04/01 21:07:47 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_error_np(char *dirname)
{
	DIR		*dir;

	dir = opendir(dirname);
	if (ft_is_file(dirname) == -1)
		return (0);
	if (dir == NULL && ft_type(dirname) == 'd')
		return (0);
	if (dir != NULL)
		closedir(dir);
	return (1);
}
