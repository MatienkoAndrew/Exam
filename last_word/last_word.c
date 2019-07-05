/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:04:58 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/05 16:05:07 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    check_word(char *str, int *i)
{
    while (str[*i] != ' ' && str[*i] != '\t' && str[*i])
        (*i)++;
}

void    print(char *str, int start, int end)
{
    while (start < end)
    {
        write(1, &str[start], 1);
        start++;
    }
}

int     main(int argc, char **argv)
{
    int     i;
    int     start = 0;
    int     end = 0;

    i = 0;
    if (argc == 2)
    {
        while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i])
            i++;
        while (argv[1][i])
        {
                start = i;
                check_word(argv[1], &i);
                end = i;
            while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i])
                i++;
            if (!argv[1][i])
                print(argv[1], start, end);
        }
    }
    write(1, "\n", 1);
    return (0);
}