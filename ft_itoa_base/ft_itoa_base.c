/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 10:10:47 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/18 11:41:32 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	int		len;
	long	nbr;
	int     sign;
	char	*pointer;
	char	base_string[17] = "0123456789ABCDEF";

	if (value == 0)
		return ("0");
	len = 0;
	nbr = value < 0 ? -value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	len = (sign == -1) ? 2 : 1;
	while ((nbr /= base))
		len++;
	nbr = value;
	if (nbr < 0)
		nbr = -nbr;
	if (!(pointer = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	pointer[len] = '\0';
	while (nbr)
	{
		pointer[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
		pointer[0] = '-';
	return (pointer);
}

int     main()
{
    char    *ar;

    printf("%s", ar = ft_itoa_base(11, 2));
    return (0);
}
