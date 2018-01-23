/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:12:49 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/23 13:28:57 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data		*ft_getdata(char *dirname, t_data **data)
{
	struct stat		fstat;
	t_data			*ptrdata;

	if (stat(dirname, &fstat) == -1)
	{
		perror("");
		exit (0);
	}
	ptrdata = *data;
	ptrdata = (t_data*)malloc(sizeof(t_data));
	ptrdata->name = ft_strdup(dirname);
	ptrdata->type = ft_strdup(ft_type(dirname));
	ptrdata->right = ft_right(fstat);
	ft_putstr("Name :");
	ft_putstr(ptrdata->name);
	ft_putstr("\nType :");
	ft_putstr(ptrdata->type);
	ft_putstr("\nRight :");
	ft_putright(ptrdata->right);
	return (ptrdata);
}
