/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:28:28 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/05 15:31:40 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_mirror(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		if (*str >= 'A' && *str <= 'Z')
			c = 'Z' - *str + 'A';
		else if (*str >= 'a' && *str <= 'z')
			c = 'z' - *str + 'a';
		write(1, &c, 1);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}
