/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:57:03 by cgaspart          #+#    #+#             */
/*   Updated: 2017/12/20 11:18:46 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabascii(char **tab)
{
	int		i;
	char	*buff;
	char	*buff2;

	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			buff = ft_strdup(tab[i]);
			buff2 = ft_strdup(tab[i + 1]);
			tab[i] = ft_strdup(buff2);
			tab[i + 1] = ft_strdup(buff);
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}
