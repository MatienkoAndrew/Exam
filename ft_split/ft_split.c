/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:55:17 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/05 19:03:43 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**words;

	i = 0;
	j = 0;
	if (!(words = (char **)malloc(sizeof(char *) * 256)))
		return (NULL);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i])
	{
		k = 0;
		if (!(words[j] = (char *)malloc(sizeof(char) * 1000)))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			words[j][k++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		words[j][k] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);	
}
