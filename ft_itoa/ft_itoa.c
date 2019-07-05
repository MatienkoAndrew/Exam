/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:44:30 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/05 16:44:33 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_itoa(int nbr)
{
    int     tmp;
    int     len = 0;
    int     neg = 0;
    char    *array;

    if (nbr == 0)
        return ("0");
    if (nbr == -2147483648)
        return ("-2147483648");
    if (nbr < 0)
    {
        len++;
        nbr = -nbr;
        neg = 1;
    }
    tmp = nbr;
    while (tmp > 0)
    {
        tmp /= 10;
        len++;
    }
    if (!(array = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    array[len] = '\0';
    len--;
    while (nbr > 0)
    {
        array[len] = (nbr % 10) + '0';
        nbr /= 10;
        len--;
    }
    if (neg == 1)
        array[0] = '-';
    return (array);
}

int     main()
{
    int     a = 2147483647;
    printf("%s", ft_itoa(a));
    return (0);
}