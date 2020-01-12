/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:58:43 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/18 11:45:54 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)
{
    int     i;
    int     nbr;

    if (argc == 2)
    {
        i = 1;
        nbr = atoi(argv[1]);
        if (nbr == 1)
            printf("1");
        while (nbr >= ++i)
        {
            if (nbr % i == 0)
            {
                printf("%d", i);
                if (nbr == i)
                    break;
                printf("*");
                nbr /= i;
                i = 1;
            }
        }
    }
    printf("\n");
    return (0);
}
