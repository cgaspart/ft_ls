/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:28:42 by cgaspart          #+#    #+#             */
/*   Updated: 2018/02/02 09:28:45 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_data	*ft_getlst(char *name, t_data **data)
{
	t_data	*ptrdata;

	ptrdata = *data;
	while (ptrdata)
	{
		if (ft_issame(ptrdata->name, name))
		{
			return (ptrdata);
		}
		ptrdata = ptrdata->next;
	}
	return (NULL);
}

void		ft_sort_lst(t_data **data, char **ascii)
{
    t_data      *glist;
    int         i;

    i = 0;
    while (ascii[i])
    {
        glist = ft_getlst(ascii[i], data);
		if (glist != NULL)
        	glist->id = i;
        i++;
    }
}
