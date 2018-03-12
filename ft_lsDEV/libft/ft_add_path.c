/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:46:25 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/01 16:46:29 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_str_path(char *str, char *dirname)
{
	char *fresh;

	fresh = ft_strdup(dirname);
	fresh = ft_strjoin(dirname, "/");
	fresh = ft_strjoin(fresh, str);
	return (fresh);
}

char	**ft_add_tab_path(char **tab, char *dirname)
{
	int i;

	i = 0;
	while (tab[i])
	{
		tab[i] = ft_add_str_path(tab[i], dirname);
		i++;
	}
	return (tab);
}
