/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:21:57 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/18 11:43:46 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

int     main(int argc, char **argv)
{
    int     i;
    int     loop;
    char    *pointer;

    if (argc == 2)
    {
        i = 0;
        if (!(pointer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
            return (-1);
        while (i <= BUFF_SIZE)
            pointer[i++] = '\0';
        i = 0;
        while (argv[1][i])
        {
            argv[1][i] == '>' ? pointer++ : pointer;
            argv[1][i] == '<' ? pointer-- : pointer;
            argv[1][i] == '+' ? (*pointer)++ : *pointer;
            argv[1][i] == '-' ? (*pointer)-- : *pointer;
            if (argv[1][i] == '.')
                write(1, &*pointer, 1);
            if (argv[1][i] == '[' && !*pointer)
            {
                loop = 1;
                while (loop)
                {
                    i++;
                    argv[1][i] == '[' ? loop++ : loop;
                    argv[1][i] == ']' ? loop-- : loop;
                }
            }
            if (argv[1][i] == ']' && *pointer)
            {
                loop = 1;
                while (loop)
                {
                    i--;
                    argv[1][i] == ']' ? loop++ : loop;
                    argv[1][i] == '[' ? loop-- : loop;
                }
            }
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}
