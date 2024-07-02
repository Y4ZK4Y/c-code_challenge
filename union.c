/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    unify(char *str1, char *str2)
{
    int i;
    i = 0;
    int seen[256] = {0};
    while (str1[i])
    {
        if (!seen[(int)str1[i]])
        {
            ft_putchar(str1[i]);
            seen[(int)str1[i]] = 1;
        }
        i++;
    }
    i = 0;
    while (str2[i])
    {
        if (!seen[(int)str2[i]])
        {
            ft_putchar(str2[i]);
            seen[(int)str2[i]] = 1;
        }
        i++;
    }
}


int main(int argc, char **argv)
{
    if (argc == 3)
    {
        unify(argv[1], argv[2]);
        ft_putchar('\n');
    }
    else
        ft_putchar('\n');
    return (0);
}