/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:17:24 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/12 13:51:20 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *ft_type(struct stat fstat)
{
    if (S_ISDIR (fstat.st_mode))
        return ("Dossier\n");
    if (S_ISSOCK (fstat.st_mode))
        return ("Socket\n");
    if (S_ISREG (fstat.st_mode))
        return ("Fichier ordinaire\n");
    if (S_ISFIFO (fstat.st_mode))
        return ("Fichier FIFO\n");
    if (S_ISCHR (fstat.st_mode))
        return ("Fichier special type char\n");
    if (S_ISBLK (fstat.st_mode))
        return ("Fichier special type bloc\n");
    return (NULL);
}
