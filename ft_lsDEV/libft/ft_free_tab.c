/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:36:42 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/15 17:36:44 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab[1] == NULL)
		free(tab);
	else if (tab != NULL)
	{
		ft_puttab(tab);
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
