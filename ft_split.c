/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 15:15:57 by abeznik       #+#    #+#                 */
/*   Updated: 2022/09/13 17:20:14 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int skip_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

char **split_f(char *str1)
{
    char **a = malloc(1024); // allocate double array
    int i = 0, x = 0, y = 0;
    while (str1[i]) // loop until str1 is null
    {
        while (skip_space(str1[i]) && str1[i]) // loop until skipped all spaces
            i++;
        if (!str1[i]) // str1 is null after spaces => only spaces
            break ;
        a[x] = malloc(1024); // allocate array
        while (!skip_space(str1[i]) && str1[i]) // loop until find a new space
            a[x][y++] = str1[i++]; // copy str1 to x-th array of a, incrementing y and i
        a[x++][y] = 0; // NULL terminate x-th array of a
        y = 0; // reset y to 0
    }
    a[x][y] = NULL; // NULL terminate the array
    return (a);
}

int main(void)
{
    char    **str;
    int     i;

    str = split_f("hello to you");
    i = 0;
    while (str[i])
    {
        printf("%s\n", str[i]);
        i++;
    }
    return (0);
}
