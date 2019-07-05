/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:34:33 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/05 15:35:38 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     inter(char *str, char c, int len)
{
    int     i;

    i = 0;
    while (str[i] && (i < len || len == -1))
        if (str[i++] == c)
            return (1);
    return (0);
}

int     main(int argc, char **argv)
{
    int     i;

    i = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (!(inter(argv[1], argv[1][i], i)) && inter(argv[2], argv[1][i], -1))
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}