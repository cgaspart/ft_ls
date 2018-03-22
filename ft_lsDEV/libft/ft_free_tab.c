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
	if (tab[1] == NULL && tab[0] != NULL)
	{
		free(tab);
		tab = NULL;
	}
	else if (tab != NULL)
	{
		while (tab[i])
		{
			if (tab[i] != NULL)
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		if (tab[i] != NULL)
		{
			free(tab);
			tab = NULL;
		}
	}
}
