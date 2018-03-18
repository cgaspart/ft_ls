/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:35:33 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/01 16:35:35 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rm_str_path(char *str)
{
	char	*res;
	int 	len;
	int 	i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	if (ft_strchr(str, '/'))
	{
		while (str[len] != '/')
		{
			i++;
			len--;
		}
		res = malloc(sizeof(char) * i + 1);
		i = 0;
		len++;
		while (str[len + i] != '\0')
		{
			res[i] = str[len + i];
			i++;
		}
		res[i] = '\0';
		free(str);
		return (res);
	}
	return (str);
}

char	**ft_rm_tab_path(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		tab[i] = ft_rm_str_path(tab[i]);
		i++;
	}
	return (tab);
}