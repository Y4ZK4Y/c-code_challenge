/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
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

void    rev_print(char *str)
{
    size_t  len;
    len = ft_strlen(str);
    while (--len > 0)
        ft_putchar(str[len]);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        rev_print(argv[1]);
        ft_putchar('\n');
    }
    ft_putchar('\n');
    return (0);
}