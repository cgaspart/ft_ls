/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:22:36 by cgaspart          #+#    #+#             */
/*   Updated: 2018/01/25 11:22:39 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int  ft_get_total(t_data *data)
{
    t_data  *ptrdata;
    int     res;

    ptrdata = data;
    res = 0;
    while (ptrdata)
    {
        res = res + ptrdata->link;
        ptrdata = ptrdata->next;
    }
    return (res);
}

void    ft_print_l(t_data **data)
{
    
}