/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:08:21 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/13 11:07:52 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
    int     i;
    int     j;
    int     num;
    char    words[256][4096];

    if (argc == 2)
    {
        i = 0;
        j = 0;
        num = 0;
        while (argv[1][i])
        {
            if (argv[1][i] == ' ')
            {
                num++;
                i++;
                j = 0;
            }
            words[num][j] = argv[1][i];
            i++;
            j++;
        }
        j = 0;
        while (num >= 0)
        {
            if (words[num][j] == '\0')
            {
                if (num > 0)
                    write(1, " ", 1);
                if (num == 0 && words[num][j] == '\0')
                    break;
                num--;
                j = 0;
            }
            write(1, &words[num][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
